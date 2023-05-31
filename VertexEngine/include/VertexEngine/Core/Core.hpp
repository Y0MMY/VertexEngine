#pragma once

#include <memory>

#define VERTEX_BUILD_ID "v0.1A - Debug"
#define BIT(x) (1u << x)
#define VERTEX_CREATE_APPLICATION(x) \
	Vertex::Application* Vertex::CreateApplication() \
	{ \
		x \
	};

#include "VEAssert.hpp"

namespace Vertex
{
	using u32 = uint32_t;
	using byte = std::byte;

	void InitializeCore();
}