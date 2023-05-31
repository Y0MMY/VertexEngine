#pragma once

#ifdef VE_PLATFORM_WINDOWS
#define VE_DEBUG_BREAK __debugbreak()
#else
#define VE_DEBUG_BREAK
#endif

#ifdef VE_DEBUG
#define VE_ENABLE_ASSERTS
#endif

#define VE_ENABLE_VERIFY

#ifdef VE_ENABLE_ASSERTS
#define VE_CORE_ASSERT_MESSAGE_INTERNAL(...)  ::Vertex::Log::PrintAssertMessage(::Vertex::Log::Type::Core, "Assertion Failed", __VA_ARGS__)
#define VE_ASSERT_MESSAGE_INTERNAL(...)  ::Vertex::Log::PrintAssertMessage(::Vertex::Log::Type::Client, "Assertion Failed", __VA_ARGS__)

#define VE_CORE_ASSERT(condition, ...) { if(!(condition)) { VE_CORE_ASSERT_MESSAGE_INTERNAL(__VA_ARGS__); VE_DEBUG_BREAK; } }
#define VE_ASSERT(condition, ...) { if(!(condition)) { VE_ASSERT_MESSAGE_INTERNAL(__VA_ARGS__); VE_DEBUG_BREAK; } }
#else
#define VE_CORE_ASSERT(condition, ...)
#define VE_ASSERT(condition, ...)
#endif

#ifdef VE_ENABLE_VERIFY
#define VE_CORE_VERIFY_MESSAGE_INTERNAL(...)  ::Vertex::Log::PrintAssertMessage(::Vertex::Log::Type::Core, "Verify Failed", __VA_ARGS__)
#define VE_VERIFY_MESSAGE_INTERNAL(...)  ::Vertex::Log::PrintAssertMessage(::Vertex::Log::Type::Client, "Verify Failed", __VA_ARGS__)

#define VE_CORE_VERIFY(condition, ...) { if(!(condition)) { VE_CORE_VERIFY_MESSAGE_INTERNAL(__VA_ARGS__); VE_DEBUG_BREAK; } }
#define VE_VERIFY(condition, ...) { if(!(condition)) { VE_VERIFY_MESSAGE_INTERNAL(__VA_ARGS__); VE_DEBUG_BREAK; } }
#else
#define VE_CORE_VERIFY(condition, ...)
#define VE_VERIFY(condition, ...)
#endif
