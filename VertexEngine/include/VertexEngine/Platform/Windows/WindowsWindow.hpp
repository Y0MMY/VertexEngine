#pragma once

#include <GLFW/glfw3.h>
#include <Core/Window.hpp>
#include <Renderer/RendererContext.hpp>

namespace Vertex
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowSpecification& specification);
		virtual ~WindowsWindow() override;

		virtual size_t GetWidth() override { return m_Specification.WindowWidth; }
		virtual size_t GetHeight() override { return m_Specification.WindowHeight; }
		virtual const std::string GetTitle() const override { return m_Specification.Title; }
		virtual Ref<RendererContext> GetRenderContext() override { return m_RendererContext; }
		
		virtual void Maximize() override;
		virtual void CenterWindow() override;

		virtual void Init() override;

		virtual void OnUpdate() override;
	private:
		GLFWwindow* m_Window = nullptr;
		WindowSpecification m_Specification;

		Ref<RendererContext> m_RendererContext;
	};
}