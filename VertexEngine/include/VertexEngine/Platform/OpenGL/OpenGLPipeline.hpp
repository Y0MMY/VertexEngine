#pragma once

#include "Renderer/Pipeline.hpp"

namespace Vertex
{
	class OpenGLPipeline : public Pipeline
	{
	public:
		OpenGLPipeline(const PipelineSpecification& spec);
		virtual ~OpenGLPipeline();

		virtual PipelineSpecification& GetSpecification() { return m_Specification; }
		virtual const PipelineSpecification& GetSpecification() const { return m_Specification; }

		virtual void Invalidate() override;

		virtual void Bind() const override;
	private:
		PipelineSpecification m_Specification;
		RendererID m_RendererID;
	};
}