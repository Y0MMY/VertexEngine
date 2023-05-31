#include "pch.hpp"
#include <Platform/Windows/WindowsWindow.hpp>

#include <Renderer/RendererAPI.hpp>

namespace Vertex 
{
	static void GLFWErrorCallback(int error, const char* description)
	{
		VE_CORE_ERROR("GLFW Error: ({}: {})", error, description);
	}

	static bool s_GLFWInitialized = false;

	WindowsWindow::WindowsWindow(const WindowSpecification& specification)
		: m_Specification(specification)
	{
		
	}

	void WindowsWindow::Init()
	{
		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			VE_CORE_VERIFY(success, "Could not intialize GLFW!");

			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;
		}
		m_Window = glfwCreateWindow((int)m_Specification.WindowWidth, (int)m_Specification.WindowHeight, m_Specification.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);

		if (RendererAPI::Current() == RendererAPIType::Vulkan)
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		m_RendererContext = RendererContext::Create(m_Window);
		m_RendererContext->Create();
		//glfwSetWindowUserPointer(m_Window, &m_Data);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}
}