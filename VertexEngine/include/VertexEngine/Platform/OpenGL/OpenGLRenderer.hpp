#pragma once

#include "Renderer/RenderPass.hpp"

#include <Renderer/RendererAPI.hpp>
#include <Renderer/VertexBuffer.hpp>
#include <Renderer/IndexBuffer.hpp>

namespace Vertex {

	class OpenGLRenderer : public RendererAPI
	{
	public:
		virtual void Init() override;
		virtual void Shutdown() override;

		virtual void BeginFrame() override;
		virtual void EndFrame() override;

		virtual void BeginRenderPass(const Ref<RenderPass>& renderPass) override{}
		virtual void EndRenderPass() override{}
		virtual void DrawIndexed(uint32_t count, PrimitiveType type, bool depthTest) override;
		// Commands
		virtual void SetFloat4(CommandFloat4Targets tar, Vector4<float> vec) override;

	private:
		float m_ClearColor[4] = { 1.f };

	};
}