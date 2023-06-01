#pragma once

#include "Core/Math/Vector.hpp"

namespace Vertex
{
	class Renderer2D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene();
		static void EndScene();

		static void FlushAndResetLines();

		// 2D
		static void DrawLine(const Vector3<float>& p0, const Vector3<float>& p1, const Vector3<float>& color = Vector3<float>(1.0f));
	};
}