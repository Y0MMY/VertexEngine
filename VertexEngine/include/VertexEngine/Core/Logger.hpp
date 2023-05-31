#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <map>

namespace Vertex
{
	class Log
	{
	public:
		enum class Type : uint8_t
		{
			Core = 0, Client = 1
		};

		enum class Level : uint8_t
		{
			Trace = 0, Info, Warn, Error, Fatal
		};

		struct TagDetails
		{
			bool Enabled = true;
			Level LevelFilter = Level::Trace;
		};
	public:
		static void Init();
		static void Shutdown();

		static bool HasTag(const std::string& tag) { return s_EnabledTags.find(tag) != s_EnabledTags.end(); }
		static std::map<std::string, TagDetails>& EnabledTags() { return s_EnabledTags; }

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		template<typename... Args>
		static void PrintMessage(Log::Type type, Log::Level level, std::string_view tag, Args&&... args);

		template<typename... Args>
		static void PrintAssertMessage(Log::Type type, std::string_view prefix, Args&&... args);
	public:
		// Enum utils
		static const char* LevelToString(Level level)
		{
			switch (level)
			{
			case Level::Trace: return "Trace";
			case Level::Info:  return "Info";
			case Level::Warn:  return "Warn";
			case Level::Error: return "Error";
			case Level::Fatal: return "Fatal";
			}
			return "";
		}
		static Level LevelFromString(std::string_view string)
		{
			if (string == "Trace") return Level::Trace;
			if (string == "Info")  return Level::Info;
			if (string == "Warn")  return Level::Warn;
			if (string == "Error") return Level::Error;
			if (string == "Fatal") return Level::Fatal;

			return Level::Trace;
		}
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

		inline static std::map<std::string, TagDetails> s_EnabledTags;
	};
}

// Core logging
#define VE_CORE_TRACE_TAG(tag, ...) ::Vertex::Log::PrintMessage(::Vertex::Log::Type::Core, ::Vertex::Log::Level::Trace, tag, __VA_ARGS__)
#define VE_CORE_INFO_TAG(tag, ...)  ::Vertex::Log::PrintMessage(::Vertex::Log::Type::Core, ::Vertex::Log::Level::Info, tag, __VA_ARGS__)
#define VE_CORE_WARN_TAG(tag, ...)  ::Vertex::Log::PrintMessage(::Vertex::Log::Type::Core, ::Vertex::Log::Level::Warn, tag, __VA_ARGS__)
#define VE_CORE_ERROR_TAG(tag, ...) ::Vertex::Log::PrintMessage(::Vertex::Log::Type::Core, ::Vertex::Log::Level::Error, tag, __VA_ARGS__)
#define VE_CORE_FATAL_TAG(tag, ...) ::Vertex::Log::PrintMessage(::Vertex::Log::Type::Core, ::Vertex::Log::Level::Fatal, tag, __VA_ARGS__)

// Core logging
#define VE_TRACE_TAG(tag, ...) ::Vertex::Log::PrintMessage(::Vertex::Log::Type::Client, ::Vertex::Log::Level::Trace, tag, __VA_ARGS__)
#define VE_INFO_TAG(tag, ...)  ::Vertex::Log::PrintMessage(::Vertex::Log::Type::Client, ::Vertex::Log::Level::Info, tag, __VA_ARGS__)
#define VE_WARN_TAG(tag, ...)  ::Vertex::Log::PrintMessage(::Vertex::Log::Type::Client, ::Vertex::Log::Level::Warn, tag, __VA_ARGS__)
#define VE_ERROR_TAG(tag, ...) ::Vertex::Log::PrintMessage(::Vertex::Log::Type::Client, ::Vertex::Log::Level::Error, tag, __VA_ARGS__)
#define VE_FATAL_TAG(tag, ...) ::Vertex::Log::PrintMessage(::Vertex::Log::Type::Client, ::Vertex::Log::Level::Fatal, tag, __VA_ARGS__)

///////////////////////////////////////////////////////////////////////////////////////////////////

// Core Logging Macros
#define VE_CORE_TRACE(...)	::Vertex::Log::PrintMessage(::Vertex::Log::Type::Core, ::Vertex::Log::Level::Trace, "", __VA_ARGS__)
#define VE_CORE_INFO(...)	::Vertex::Log::PrintMessage(::Vertex::Log::Type::Core, ::Vertex::Log::Level::Info, "", __VA_ARGS__)
#define VE_CORE_WARN(...)	::Vertex::Log::PrintMessage(::Vertex::Log::Type::Core, ::Vertex::Log::Level::Warn, "", __VA_ARGS__)
#define VE_CORE_ERROR(...)	::Vertex::Log::PrintMessage(::Vertex::Log::Type::Core, ::Vertex::Log::Level::Error, "", __VA_ARGS__)
#define VE_CORE_FATAL(...)	::Vertex::Log::PrintMessage(::Vertex::Log::Type::Core, ::Vertex::Log::Level::Fatal, "", __VA_ARGS__)

// CLient Logging Macros
#define VE_TRACE(...)		::Vertex::Log::PrintMessage(::Vertex::Log::Type::Client, ::Vertex::Log::Level::Trace, "", __VA_ARGS__)
#define VE_INFO(...)		::Vertex::Log::PrintMessage(::Vertex::Log::Type::Client, ::Vertex::Log::Level::Info, "", __VA_ARGS__)
#define VE_WARN(...)		::Vertex::Log::PrintMessage(::Vertex::Log::Type::Client, ::Vertex::Log::Level::Warn, "", __VA_ARGS__)
#define VE_ERROR(...)		::Vertex::Log::PrintMessage(::Vertex::Log::Type::Client, ::Vertex::Log::Level::Error, "", __VA_ARGS__)
#define VE_FATAL(...)		::Vertex::Log::PrintMessage(::Vertex::Log::Type::Client, ::Vertex::Log::Level::Fatal, "", __VA_ARGS__)

namespace Vertex {

	template<typename... Args>
	void Log::PrintMessage(Log::Type type, Log::Level level, std::string_view tag, Args&&... args)
	{
		auto detail = s_EnabledTags[std::string(tag)];
		if (detail.Enabled && detail.LevelFilter <= level)
		{
			auto logger = (type == Type::Core) ? GetCoreLogger() : GetClientLogger();
			std::string logString = tag.empty() ? "{0}{1}" : "[{0}] {1}";
			switch (level)
			{
			case Level::Trace:
				logger->trace(logString, tag, fmt::format(std::forward<Args>(args)...));
				break;
			case Level::Info:
				logger->info(logString, tag, fmt::format(std::forward<Args>(args)...));
				break;
			case Level::Warn:
				logger->warn(logString, tag, fmt::format(std::forward<Args>(args)...));
				break;
			case Level::Error:
				logger->error(logString, tag, fmt::format(std::forward<Args>(args)...));
				break;
			case Level::Fatal:
				logger->critical(logString, tag, fmt::format(std::forward<Args>(args)...));
				break;
			}
		}
	}

	template<typename... Args>
	void Log::PrintAssertMessage(Log::Type type, std::string_view prefix, Args&&... args)
	{
		auto logger = (type == Type::Core) ? GetCoreLogger() : GetClientLogger();
		logger->error("{0}: {1}", prefix, fmt::format(std::forward<Args>(args)...));
	}

	template<>
	inline void Log::PrintAssertMessage(Log::Type type, std::string_view prefix)
	{
		auto logger = (type == Type::Core) ? GetCoreLogger() : GetClientLogger();
		logger->error("{0}", prefix);
	}
}