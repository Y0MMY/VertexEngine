#pragma once

#include "Core/Application.hpp"
#include "Renderer/RendererContext.hpp"
#include "Memory/RenderCommandQueue.hpp"
#include "Renderer/RendererAPI.hpp"
#include "Renderer2D/Renderer2D.hpp"

namespace Vertex
{
	class Renderer
	{
	public:
		static Ref<RendererContext> GetContext()
		{
			return {};
		}
		// Commands
		static void SetFloat4(CommandFloat4Targets command, Vector4<float> vec);
		//
		static void Init();

		static void BeginFrame();
		static void EndFrame();
		static void BeginRenderPass(Ref<RenderPass> renderPass, bool clear);
		static void EndRenderPass();
		static void DrawIndexed(uint32_t count, PrimitiveType type, bool depthTest);

		template<typename FuncT>
		static void Submit(FuncT&& func)
		{
			auto renderCMD = [](void* ptr)
			{
				auto pFunc = (FuncT*)ptr;
				(*pFunc)();
				pFunc->~FuncT();
			};
			
			auto storage = GetRenderCommandQueue().AddCommand(renderCMD, sizeof(FuncT));
			new (storage) FuncT(std::forward<FuncT>(func));
		}
		static void WaitAndRender();
	private:
		static RenderCommandQueue& GetRenderCommandQueue();
	};
}