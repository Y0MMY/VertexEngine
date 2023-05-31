#pragma once

namespace Vertex
{
	enum class RendererAPIType
	{
		None,
		Vulkan,
		OpenGL
	};

	class RendererAPI
	{
	public:
		virtual void Init() = 0;
		virtual void Shutdown() = 0;

		virtual void BeginFrame() = 0;
		virtual void EndFrame() = 0;

		static RendererAPIType Current() { return s_CurrentRendererAPI; }
	private:
		inline static RendererAPIType s_CurrentRendererAPI = RendererAPIType::Vulkan;

	};

}