#include "pch.hpp"
#include <Platform/OpenGL/OpenGLContext.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Vertex
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
	}
	OpenGLContext::~OpenGLContext()
	{
	}

	void OpenGLContext::Create()
	{
		VE_CORE_INFO("OpenGLContext::Create");

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		VE_CORE_ASSERT(status, "Failed to initialize Glad!");

		//VE_CORE_INFO("OpenGL Info:");
		//VE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		//VE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		//VE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

#ifdef VE_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		VE_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Vertex requires at least OpenGL version 4.5!");
#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}