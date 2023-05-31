#include <fstream>
#include <sstream>

#include <string>
#include <filesystem>

#include <unordered_map>
#include <unordered_set>
#include <array>

#if defined(VE_PLATFORM_WINDOWS)
	#include <Windows.h>
#endif

// Core
#include "Core/Core.hpp"
#include "Core/Logger.hpp"
#include "Memory/Unique.hpp"
#include "Memory/Ref.hpp"
#include "Memory/Buffer.hpp"

// Renderer
#include "Renderer/RendererContext.hpp"