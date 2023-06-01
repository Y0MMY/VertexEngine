#pragma once

//NOTE: This is a workaround for Microsoft macros so that 
//we can use names like CreateDirectory, etc

#ifdef CreateDirectory
#undef CreateDirectory
#undef DeleteFile
#undef MoveFile
#undef CopyFile
#undef SetEnvironmentVariable
#undef GetEnvironmentVariable
#endif

#include <functional>
#include <filesystem>

namespace Vertex::Utils
{
	class FileSystem
	{
	public:
		static bool CreateDirectory(const std::filesystem::path& directory);
		static bool CreateDirectory(const std::string& directory);
		static bool Exists(const std::filesystem::path& filepath);
		static bool Exists(const std::string& filepath);
		static const std::string GetFileName(const std::filesystem::path& filepath);
		static const std::string GetFileName(const std::string& filepath);
	public:
		static std::filesystem::path OpenFileDialog(const char* filter = "All\0*.*\0");
		static std::filesystem::path OpenFolderDialog(const char* initialFolder = "");
		static std::filesystem::path SaveFileDialog(const char* filter = "All\0*.*\0");
	public:
		static bool HasEnvironmentVariable(const std::string& key);
		static bool SetEnvironmentVariable(const std::string& key, const std::string& value);
		static std::string GetEnvironmentVariable(const std::string& key);
	};
}