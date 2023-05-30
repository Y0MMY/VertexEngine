#pragma once
//#include <Platform/Windows/WindowsWindow.hpp>

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
		Window(const WindowSpecification& specification)
			: m_S(specification)
		{

		}
		WindowSpecification m_S; //NOTE: Tempory varibale while we dont have a platform realization
	};
}