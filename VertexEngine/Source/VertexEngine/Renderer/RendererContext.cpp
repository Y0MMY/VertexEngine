#include "pch.hpp"
#include <Renderer/RendererContext.hpp>
#include <Renderer/RendererAPI.hpp>
#include <Platform/Vulkan/Renderer/VulkanContext.hpp>
#include <Platform/OpenGL/OpenGLContext.hpp>

namespace Vertex
{
	Ref<RendererContext> RendererContext::Create(GLFWwindow* windowHandle)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    return nullptr;
			case RendererAPIType::OpenGL:  return Ref<OpenGLContext>::Create(windowHandle);
			//case RendererAPIType::Vulkan:  return Ref<VulkanContext>::Create(windowHandle);
		}
		VE_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}