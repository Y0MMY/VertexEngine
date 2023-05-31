#pragma once

#include <Vulkan/vulkan.h>// NOTE: This is include from Vulkan SDK

#include "Memory/Ref.hpp"

#include <Renderer/Renderer.hpp>
#include <Renderer/RendererContext.hpp>
#include <Platform/Vulkan/Renderer/VulkanDevice.hpp>

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

		//Ref<VulkanDevice> GetDevice() { return m_Device; }

		static VkInstance GetInstance() { return s_VulkanInstance; }
		/*static Ref<VulkanContext> Get() { return Ref<VulkanContext>(Renderer::GetContext()); }
		static Ref<VulkanDevice> GetCurrentDevice() { return {}; }*/
	private:
		GLFWwindow* m_WindowHandle;
		inline static VkInstance s_VulkanInstance;

		//Ref<VulkanDevice> m_Device;

		//VulkanAllocator m_Allocator;
		//VulkanSwapChain m_SwapChain;


	};
}