#pragma once

#include "Renderer.hpp"

namespace Vertex
{
	enum class VertexBufferUsage
	{
		None = 0, Static = 1, Dynamic = 2
	};

	class VertexBuffer : public RefCounted
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void SetData(void* data, u32 size, u32 offset = 0) = 0;
		virtual void Bind() const = 0;

		virtual u32 GetSize() const = 0;
		virtual RendererID GetRendererID() const = 0;

		static Ref<VertexBuffer> Create(void* data, u32 size, VertexBufferUsage usage = VertexBufferUsage::Static);
		static Ref<VertexBuffer> Create(u32 size, VertexBufferUsage usage = VertexBufferUsage::Dynamic);
	};
}