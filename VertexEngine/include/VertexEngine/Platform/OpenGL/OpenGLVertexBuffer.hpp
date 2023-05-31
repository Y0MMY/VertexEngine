#pragma once

#include "Renderer/VertexBuffer.hpp"
#include <Memory/Buffer.hpp>

namespace Vertex
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(void* data, uint32_t size, VertexBufferUsage usage = VertexBufferUsage::Static);
		OpenGLVertexBuffer(uint32_t size, VertexBufferUsage usage = VertexBufferUsage::Dynamic);
		~OpenGLVertexBuffer() override;

		virtual void SetData(void* data, u32 size, u32 offset) override;
		virtual void Bind() const override;

		virtual u32 GetSize() const { return m_Size; }
		virtual RendererID GetRendererID() const { return m_RendererID; }
	private:
		Buffer m_LocalData;
		u32 m_Size = 0;

		VertexBufferUsage m_Usage;

		RendererID m_RendererID = 0;
	};
}