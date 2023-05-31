#include "pch.hpp"
#include <Renderer/IndexBuffer.hpp>
#include <Platform/OpenGL/OpenGLIndexBuffer.hpp>

#include <Renderer/RendererAPI.hpp>

namespace Vertex
{
	Ref<IndexBuffer> IndexBuffer::Create(void* data, u32 size)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::None:
			return nullptr;

		case RendererAPIType::OpenGL:
			return Ref<OpenGLIndexBuffer>::Create(data, size);
		}

		VE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(u32 size)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::None:  return nullptr;
		case RendererAPIType::OpenGL: return Ref<OpenGLIndexBuffer>::Create(size);
		}

		VE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}