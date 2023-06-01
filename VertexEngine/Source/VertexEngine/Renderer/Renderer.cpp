#include "pch.hpp"
#include <Renderer/Renderer.hpp>
#include <Platform/Vulkan/Renderer/VulkanRenderer.hpp>
#include <Platform/OpenGL/OpenGLRenderer.hpp>

namespace Vertex
{
	static RendererAPI* s_RendererAPI = nullptr;

	RenderCommandQueue* s_CommandQueue = nullptr;

	static RendererAPI* InitRendererAPI()
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::Vulkan: return new VulkanRenderer();
			case RendererAPIType::OpenGL: return new OpenGLRenderer();
		}
		VE_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}


	void Renderer::Init()
	{
		s_CommandQueue = new RenderCommandQueue();
		s_RendererAPI = InitRendererAPI();
		s_RendererAPI->Init();
		Renderer2D::Init();
	}

	void Renderer::BeginFrame()
	{
		s_RendererAPI->BeginFrame();
	}

	void Renderer::EndFrame()
	{
		s_RendererAPI->EndFrame();

	}

	void Renderer::SetFloat4(CommandFloat4Targets command, Vector4<float> parameters)
	{
		s_RendererAPI->SetFloat4(command, parameters);
	}

	void RendererAPI::SetAPI(RendererAPIType api)
	{
		// TODO: make sure this is called at a valid time
		s_CurrentRendererAPI = api;
	}

	RenderCommandQueue& Renderer::GetRenderCommandQueue()
	{
		return *s_CommandQueue;
	}

	void Renderer::WaitAndRender()
	{
		s_CommandQueue->Execute();
	}

	void Renderer::BeginRenderPass(Ref<RenderPass> renderPass, bool clear)
	{
		s_RendererAPI->BeginRenderPass(renderPass);
	}

	void Renderer::EndRenderPass()
	{
		s_RendererAPI->EndRenderPass();
	}

	void Renderer::DrawIndexed(uint32_t count, PrimitiveType type, bool depthTest)
	{
		s_RendererAPI->DrawIndexed(count, type, depthTest);
	}

}