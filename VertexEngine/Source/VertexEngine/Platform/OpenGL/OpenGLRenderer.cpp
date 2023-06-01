#include "pch.hpp"
#include <Platform/OpenGL/OpenGLRenderer.hpp>

#include <glad/glad.h>
#include <Renderer/Pipeline.hpp>
#include <Renderer/Shader.hpp>

namespace Vertex
{
	struct OpenGLRendererData
	{
		Ref<VertexBuffer> m_FullscreenQuadVertexBuffer;
		Ref<IndexBuffer> m_FullscreenQuadIndexBuffer;
		Ref<Pipeline> m_FullscreenQuadPipeline;
		Ref<Shader> m_Shader;
	};

	struct OpenGLGUIData
	{
		Ref<VertexBuffer> m_GUIVertexBuffer;
		Ref<IndexBuffer> m_GUIIndexBuffer;
		Ref<Pipeline> m_GUIPipeline;
		Ref<Shader> m_GUIShader;
	};

	static OpenGLRendererData* s_Data = nullptr;

	namespace Utils {

		static void Clear(float r, float g, float b, float a)
		{
			glClearColor(r, g, b, a);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		}

		static void SetClearColor(float r, float g, float b, float a)
		{
			glClearColor(r, g, b, a);
		}

		static void DrawIndexed(uint32_t count, PrimitiveType type, bool depthTest)
		{
			if (!depthTest)
				glDisable(GL_DEPTH_TEST);

			GLenum glPrimitiveType = 0;
			switch (type)
			{
			case PrimitiveType::Triangles:
				glPrimitiveType = GL_TRIANGLES;
				break;
			case PrimitiveType::Lines:
				glPrimitiveType = GL_LINES;
				break;
			}

			glDrawElements(glPrimitiveType, count, GL_UNSIGNED_INT, nullptr);

			if (!depthTest)
				glEnable(GL_DEPTH_TEST);
		}

		static void SetLineThickness(float thickness)
		{
			glLineWidth(thickness);
		}

		static void OpenGLLogMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
		{
			switch (severity)
			{
			case GL_DEBUG_SEVERITY_HIGH:
				VE_CORE_ERROR("[OpenGL Debug HIGH] {0}", message);
				VE_CORE_ASSERT(false, "GL_DEBUG_SEVERITY_HIGH");
				break;
			case GL_DEBUG_SEVERITY_MEDIUM:
				VE_CORE_WARN("[OpenGL Debug MEDIUM] {0}", message);
				break;
			case GL_DEBUG_SEVERITY_LOW:
				VE_CORE_INFO("[OpenGL Debug LOW] {0}", message);
				break;
			case GL_DEBUG_SEVERITY_NOTIFICATION:
				// VE_CORE_TRACE("[OpenGL Debug NOTIFICATION] {0}", message);
				break;
			}
		}

	}


	void OpenGLRenderer::Init()
	{
		s_Data = new OpenGLRendererData();

		float x = -1, y = -1;
		float width = 2, height = 2;
		struct QuadVertex
		{
			Vector3<float> Position;
			Vector2<float> TexCoord;
		};

		QuadVertex* data = new QuadVertex[4];

		data[0].Position = Vector3<float>(x, y, 0.1f);
		data[0].TexCoord = Vector2<float>(0, 0);

		data[1].Position = Vector3<float>(x + width, y, 0.1f);
		data[1].TexCoord = Vector2<float>(1, 0);

		data[2].Position = Vector3<float>(x + width, y + height, 0.1f);
		data[2].TexCoord = Vector2<float>(1, 1);

		data[3].Position = Vector3<float>(x, y + height, 0.1f);
		data[3].TexCoord = Vector2<float>(0, 1);

		PipelineSpecification pipelineSpecification;
		pipelineSpecification.Layout = {
			{ ShaderDataType::Float3, "a_Position" },
			{ ShaderDataType::Float2, "a_TexCoord" }
		};
		s_Data->m_FullscreenQuadPipeline = Pipeline::Create(pipelineSpecification);

		s_Data->m_FullscreenQuadVertexBuffer = VertexBuffer::Create(data, 4 * sizeof(QuadVertex));
		uint32_t indices[6] = { 0, 1, 2, 2, 3, 0, };
		s_Data->m_FullscreenQuadIndexBuffer = IndexBuffer::Create(indices, 6 * sizeof(uint32_t));
		s_Data->m_Shader = Shader::Create("Resources/Shaders/Shader.veshader");
	}

	void OpenGLRenderer::Shutdown()
	{
		delete s_Data;
	}

	void OpenGLRenderer::BeginFrame()
	{
		s_Data->m_FullscreenQuadIndexBuffer->Bind();
		s_Data->m_FullscreenQuadVertexBuffer->Bind();
		s_Data->m_FullscreenQuadPipeline->Bind();
		s_Data->m_Shader->Bind();
		Renderer::Submit([]()
			{
				Utils::DrawIndexed(6, PrimitiveType::Triangles, false);
			});

	}
	
	void OpenGLRenderer::EndFrame()
	{
		Utils::Clear(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void OpenGLRenderer::DrawIndexed(uint32_t count, PrimitiveType type, bool depthTest)
	{
		Utils::DrawIndexed(count, type, depthTest);
	}

	// Commands
	void OpenGLRenderer::SetFloat4(CommandFloat4Targets target, Vector4 <float> parameters)
	{
		switch (target)
		{
		case CommandFloat4Targets::SetBackgroundColor:
			s_Data->m_Shader->SetFloat4("u_Color", { 1.0, .2f,.3f, 1.f });
			break;
		}
	}
}