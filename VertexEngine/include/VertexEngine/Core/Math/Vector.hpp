#pragma once

namespace Vertex
{
	template <typename T = float>
	struct Vector4
	{
		T x, y, z, w;
	};

	template <typename T = float>
	struct Vector3
	{
		constexpr Vector3() = default;
		constexpr Vector3(T x) 
			: x(x),y(x),z(x) {}
		constexpr Vector3(T x, T y, T z)
			: x(x),y(y),z(z){}
		T x, y, z;
	};

	template <typename T = float>
	struct Vector2
	{
		Vector2() = default;
		Vector2(T x, T y)
			: x(x), y(y) {}
		T x, y;
	};
}