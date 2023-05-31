#pragma once

#include <Renderer/RendererAPI.hpp>

namespace Vertex
{
	class VulkanRenderer : public RendererAPI
	{
		virtual void Init() override;
		virtual void Shutdown() override;

		virtual void BeginFrame() override;
		virtual void EndFrame() override;

		virtual void SetFloat4(CommandFloat4Targets command, Vector4<float> vec) override {}
	};
}