#include "pch.hpp"
#include <Platform/OpenGL/OpenGLRenderer.hpp>

#include <glad/glad.h>

namespace Vertex
{
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
		
	}

	void OpenGLRenderer::Shutdown()
	{

	}

	void OpenGLRenderer::EndFrame()
	{
	}
	
	void OpenGLRenderer::BeginFrame()
	{
		Utils::Clear(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]);
	}

	// Commands
	void OpenGLRenderer::SetFloat4(CommandFloat4Targets target, Vector4 <float> parameters)
	{
		switch (target)
		{
		case CommandFloat4Targets::SetBackgroundColor:
			m_ClearColor[0] = parameters.x;
			m_ClearColor[1] = parameters.y;
			m_ClearColor[2] = parameters.z;
			m_ClearColor[3] = parameters.w;
			break;
		}
	}
}