#pragma once

#include <string>
#include "Window.hpp"
#include "Core/Core.hpp"

namespace Vertex
{
	struct ApplicationSpecification
	{
		std::string Name = "";
		uint32_t WindowWidth = 1600, WindowHeight = 900;
		uint32_t LoadFlags = 1;

		enum ApplicationLoadFlags
		{
			None = BIT(0),
			WindowDecorated = BIT(1),
			StartMaximized = BIT(2),
			WindowResizeble = BIT(3),
			EnableImGui = BIT(4)
		};

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
		void Run();
		virtual void OnUpdate() = 0;
		virtual void OnInit() {}

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