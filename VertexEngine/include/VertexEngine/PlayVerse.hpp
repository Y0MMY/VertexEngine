#pragma once

//NOTE: This is a file containing all declarations of classes and functions 
// intended for connection to the sandbox. NEVER include it in the vertex engine itself

#include "Core/Application.hpp"
#include "Core/Core.hpp"
#include "Core/Logger.hpp"
#include "Memory/Buffer.hpp"

// Renderer
#include "Renderer/IndexBuffer.hpp"
#include "Renderer/VertexBuffer.hpp"
#include "Renderer/Pipeline.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/Renderer2D/Renderer2D.hpp"
#include "Renderer/Shader.hpp"

// Utilities
#include "Utilities/FileSystem.hpp"