#pragma once

#include "CommadsTargets.hpp"
#include "Core/Math/Vector.hpp"

namespace Vertex
{
	using RendererID = unsigned int;
	enum class RendererAPIType
	{
		None,
		Vulkan,
		OpenGL
	};

	enum class PrimitiveType
	{
		None = 0, Triangles, Lines
	};

	class RendererAPI
	{
	public:
		// Commands
		virtual void SetFloat4(CommandFloat4Targets command, Vector4<float> vec) = 0;
		//
		virtual void Init() = 0;
		virtual void Shutdown() = 0;

		virtual void BeginFrame() = 0;
		virtual void EndFrame() = 0;

		static void SetAPI(RendererAPIType api);
		
		static RendererAPIType Current() { return s_CurrentRendererAPI; }
	private:
		inline static RendererAPIType s_CurrentRendererAPI = RendererAPIType::OpenGL;

	};

}