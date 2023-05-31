#include "pch.hpp"
#include <Renderer/Renderer.hpp>
#include <Platform/Vulkan/Renderer/VulkanRenderer.hpp>

#include <Renderer/RendererAPI.hpp>

namespace Vertex
{
	static RendererAPI* s_RendererAPI = nullptr;

	static RendererAPI* InitRendererAPI()
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::Vulkan: return new VulkanRenderer();
		}
		VE_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}


	void Renderer::Init()
	{
		s_RendererAPI = InitRendererAPI();
		s_RendererAPI->Init();
	}

	void Renderer::BeginFrame()
	{
		s_RendererAPI->BeginFrame();
	}

	void Renderer::EndFrame()
	{
		s_RendererAPI->EndFrame();

	}
}