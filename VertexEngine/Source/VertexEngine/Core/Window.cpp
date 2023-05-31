#include "pch.hpp"
#include <Core/Window.hpp>

#include <Platform/Windows/WindowsWindow.hpp>	

namespace Vertex
{
	Unique<Window> Window::Create(const WindowSpecification& specification)
	{
#if defined(VE_PLATFORM_WINDOWS)
		return Unique<WindowsWindow>::Create(specification);
#endif
	}
}