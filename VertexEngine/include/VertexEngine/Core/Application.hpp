#pragma once

#include <string>
#include "Window.hpp"

#define VERTEX_CREATE_APPLICATION(x) \
	Vertex::Application* Vertex::CreateApplication() \
	{ \
		x \
	};

namespace Vertex
{
	struct ApplicationSpecification
	{
		std::string Name = "";
		uint32_t WindowWidth = 1600, WindowHeight = 900;

		enum class ApplicationMode
		{
			None = 0,
			Debug,
			Runtime,
		} Mode;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& specification);
		virtual void Run();

		virtual ~Application() {}
	private:
		Window* m_Window;
	};
	Application* CreateApplication();
}