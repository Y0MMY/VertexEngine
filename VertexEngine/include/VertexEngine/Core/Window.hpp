#pragma once

#include "Memory/Unique.hpp"
#include "Renderer/RendererContext.hpp"

namespace Vertex
{
	struct WindowSpecification
	{
		std::string Title;
		size_t WindowWidth, WindowHeight;

	};

	class Window
	{
	public:
		virtual ~Window() {}

		virtual size_t GetWidth() = 0;
		virtual size_t GetHeight() = 0;	
		virtual const std::string GetTitle() const = 0;
		virtual Ref<RendererContext> GetRenderContext() = 0;

		virtual void Init() = 0;

		virtual void OnUpdate() = 0;

		static Unique<Window> Create(const WindowSpecification& specification);
	};
}