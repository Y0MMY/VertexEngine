#pragma once

#include <Renderer/IndexBuffer.hpp>
#include <Renderer/Renderer.hpp>

namespace Vertex
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(void* data, u32 size);
		OpenGLIndexBuffer(u32 size);
		virtual ~OpenGLIndexBuffer() override;

		virtual void SetData(void* data, u32 size, u32 offset = 0) override;
		virtual void Bind() const override;

		virtual u32 GetCount() const override { return m_Size / sizeof(u32); }
		virtual u32 GetSize() const override { return m_Size; }
	private:
		Buffer m_LocalData;
		u32 m_Size = 0;
		RendererID m_RendererID = 0;
	};
}