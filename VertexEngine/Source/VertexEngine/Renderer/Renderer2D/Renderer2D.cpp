#include "pch.hpp"
#include <Renderer/Renderer2D/Renderer2D.hpp>
#include <Renderer/Pipeline.hpp>
#include <Renderer/IndexBuffer.hpp>
#include <Renderer/Shader.hpp>

namespace Vertex
{
	struct LineVertex
	{
		Vector3<float> Position;
	};

	struct Renderer2DData
	{
		// Lines
		static const u32 MaxLines = 10000;
		static const u32 MaxLineVertices = MaxLines * 4;
		static const u32 MaxLineIndices = MaxLines * 6;

		Ref<Pipeline> LinePipeline;
		Ref<VertexBuffer> LineVertexBuffer;
		Ref<IndexBuffer> LineIndexBuffer;

		Ref<Shader> LineShader;
		uint32_t LineIndexCount = 0;
		LineVertex* LineVertexBufferBase = nullptr;
		// Quad
	};

	Renderer2DData* s_Data = nullptr;

	void Renderer2D::Init()
	{
		s_Data = new Renderer2DData();

		// Lines
		{
			s_Data->LineShader = Shader::Create("Resources/Shaders/ShaderGUI.veshader");

			PipelineSpecification spec;
			spec.Layout = {
				{ ShaderDataType::Float3, "a_Position" },
			};

			s_Data->LinePipeline = Pipeline::Create(spec);
			s_Data->LineVertexBuffer = VertexBuffer::Create(s_Data->MaxLineVertices * sizeof(LineVertex));

			s_Data->LineVertexBufferBase = new LineVertex[s_Data->MaxLineIndices];

			u32* LineIndices = new u32[s_Data->MaxLineIndices];
			for (u32 i = 0; i < s_Data->MaxLineIndices; i++)
			{
				LineIndices[i] = i;
			}

			s_Data->LineIndexBuffer = IndexBuffer::Create(LineIndices, s_Data->MaxLineIndices);
			delete[] LineIndices;
		}
	}

	void Renderer2D::Shutdown()
	{
		delete s_Data;
	}

	void Renderer2D::BeginScene()
	{
		s_Data->LineIndexCount = 0;
	}

	void Renderer2D::EndScene()
	{
		auto dataSize = (uint8_t*)(s_Data->LineVertexBufferBase + s_Data->LineIndexCount) - (uint8_t*)s_Data->LineVertexBufferBase;

		if (dataSize)
		{
			s_Data->LineVertexBuffer->SetData(s_Data->LineVertexBufferBase, dataSize);

			s_Data->LineShader->Bind();

			s_Data->LinePipeline->Bind();
			s_Data->LineIndexBuffer->Bind();
			Renderer::DrawIndexed(s_Data->LineIndexCount, PrimitiveType::Lines, false);
		}
	}

	void Renderer2D::DrawLine(const Vector3<float>& p0, const Vector3<float>& p1, const Vector3<float>& color /*= Vector3<float>(1.0f)*/)
	{
		if (s_Data->LineIndexCount >= Renderer2DData::MaxLineIndices)
			FlushAndResetLines();

		s_Data->LineVertexBufferBase[s_Data->LineIndexCount].Position = p0;

		s_Data->LineIndexCount++;

		s_Data->LineVertexBufferBase[s_Data->LineIndexCount].Position = p1;

		s_Data->LineIndexCount++;
	}

	void Renderer2D::FlushAndResetLines()
	{


	}


}