#include "pch.hpp"
#include <Platform/Vulkan/Renderer/VulkanContext.hpp>

#include <Vulkan/vk_platform.h>
#include <Vulkan/vulkan_core.h>

#include <glfw/glfw3.h>

namespace Vertex
{
	static VKAPI_ATTR VkBool32 VKAPI_CALL VulkanDebugReportCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage, void* pUserData)
	{
		(void)flags; (void)object; (void)location; (void)messageCode; (void)pUserData; (void)pLayerPrefix; // Unused arguments
		VE_CORE_WARN_TAG("", "VulkanDebugCallback:\n  Object Type: {0}\n  Message: {1}", objectType, pMessage);
		return VK_FALSE;
	}

	VulkanContext::VulkanContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{

	}

	VulkanContext::~VulkanContext()
	{

	}

	void VulkanContext::Create()
	{
		VE_CORE_INFO_TAG("Renderer", "VulkanContext::Create");
		VE_CORE_ASSERT(glfwVulkanSupported(), "GLFW must support Vulkan!");

		VkApplicationInfo appInfo;
		appInfo.pEngineName = "VertexEngine";
		appInfo.pApplicationName = "PlayVerse";
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;
		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;
		createInfo.enabledLayerCount = 0;

		if (vkCreateInstance(&createInfo, nullptr, &s_VulkanInstance) != VK_SUCCESS) {
			VE_CORE_ASSERT(false, "");
		}
	}

	void VulkanContext::SwapBuffers()
	{

	}

	void VulkanContext::OnResize(uint32_t width, uint32_t height)
	{

	}

	void VulkanContext::BeginFrame()
	{

	}

}