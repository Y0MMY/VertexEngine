#pragma once

#include <string>
#include "Window.hpp"
#include "Memory/Unique.hpp"

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

		static inline Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

		virtual ~Application() {}
	private:
		Unique<Window> m_Window;
		bool m_Running;

		static Application* s_Instance;
	};
	Application* CreateApplication();
}