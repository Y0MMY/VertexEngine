#include "pch.hpp"
#include <Core/Application.hpp>

#include <Renderer/Renderer.hpp>

namespace Vertex
{
	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpecification& specification)
	{
		s_Instance = this;

		m_Window = Window::Create({ specification.Name , 444, 900 });//TODO: Debug unique class
		m_Window->Init();
		Renderer::Init();
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}