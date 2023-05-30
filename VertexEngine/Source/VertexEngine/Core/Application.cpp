#include "pch.hpp"
#include <Core/Application.hpp>

namespace Vertex
{
	Application::Application(const ApplicationSpecification& specification)
	{
		m_Window = new Window( {specification.Name , 1600, 900} );
	}

	void Application::Run()
	{
		while(true)
			printf("TEST: %s\n", m_Window->m_S.Title.c_str());
	}
}