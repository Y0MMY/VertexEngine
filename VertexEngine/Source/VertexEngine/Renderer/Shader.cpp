#include "pch.hpp"
#include <Renderer/Shader.hpp>

#include <Platform/OpenGL/OpenGLShader.hpp>

namespace Vertex
{
	Shader* Shader::Create(const std::filesystem::path& filepath)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::None: return nullptr;
		case RendererAPIType::OpenGL: return new OpenGLShader(filepath);
		}
		return nullptr;
	}

}