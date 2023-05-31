#pragma once

#include <Core/Application.hpp>
#include <Renderer/RendererContext.hpp>

namespace Vertex
{
	class Renderer
	{
	public:
		static Ref<RendererContext> GetContext()
		{
			return {};
		}

		static void Init();

		static void BeginFrame();
		static void EndFrame();
	};
}