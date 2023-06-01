#include "pch.hpp"
#include <Renderer/Pipeline.hpp>

#include <Platform/OpenGL/OpenGLPipeline.hpp>

namespace Vertex
{
	Ref<Pipeline> Pipeline::Create(const PipelineSpecification& spec)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::None:    return nullptr;
		case RendererAPIType::OpenGL:  return Ref<OpenGLPipeline>::Create(spec);
		}
		VE_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}
}