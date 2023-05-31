#pragma once

#include <Vulkan/vulkan.h>// NOTE: This is include from Vulkan SDK

#include <Renderer/RendererContext.hpp>

namespace Vertex
{
	class VulkanContext : public RendererContext
	{
	public:
		VulkanContext(GLFWwindow* windowHandle);
		virtual ~VulkanContext() override;

		virtual void Create() override;
		virtual void SwapBuffers() override;

		virtual void OnResize(uint32_t width, uint32_t height) override;

		virtual void BeginFrame() override;
	private:
		GLFWwindow* m_WindowHandle;
		inline static VkInstance s_VulkanInstance;

	};
}