#pragma once

#include "Vulkan.hpp"

namespace Vertex::Utils 
{

	struct VulkanCheckpointData
	{
		char Data[64];
	};

	void SetVulkanCheckpoint(VkCommandBuffer commandBuffer, const std::string& data);

}

