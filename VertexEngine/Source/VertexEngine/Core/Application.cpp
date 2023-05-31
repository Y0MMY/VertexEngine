#include "pch.hpp"
#include <Core/Application.hpp>

#include <Renderer/Renderer.hpp>
#include <Memory/RenderCommandQueue.hpp>

namespace Vertex
{
	Application* Application::s_Instance = nullptr;
	using LoadingFlags = ApplicationSpecification::ApplicationLoadFlags;

	Application::Application(const ApplicationSpecification& specification)
	{
		s_Instance = this;
		RendererAPI::SetAPI(RendererAPIType::OpenGL);

		m_Window = Window::Create({ specification.Name , specification.WindowWidth, specification.WindowHeight});//TODO: Debug unique class
		Renderer::Init();
		m_Window->Init();

		if (specification.LoadFlags & LoadingFlags::StartMaximized)
			m_Window->Maximize();
		else m_Window->CenterWindow();

		Renderer::WaitAndRender();
		//Utils::DrawIndexed(3, PrimitiveType::Triangles, false);o
	}

	void Application::Run()
	{
		OnInit();
		while (m_Running)
		{
			Renderer::BeginFrame();
			OnUpdate();
			m_Window->OnUpdate();
			Renderer::EndFrame();
			Renderer::WaitAndRender();
		}
	}
}