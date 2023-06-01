#include "pch.hpp"
#include <Utilities/FileSystem.hpp>

#include <filesystem>

namespace fs = std::filesystem;

namespace Vertex::Utils
{
	bool FileSystem::CreateDirectory(const std::filesystem::path& directory)
	{
		return fs::create_directory(directory);
	}

	bool FileSystem::CreateDirectory(const std::string& directory)
	{
		return CreateDirectory(fs::path(directory));
	}

	bool FileSystem::Exists(const std::filesystem::path& filepath)
	{
		return fs::exists(filepath);
	}

	bool FileSystem::Exists(const std::string& filepath)
	{
		return fs::exists(fs::path(filepath));
	}

	const std::string FileSystem::GetFileName(const std::filesystem::path& filepath)
	{
		return filepath.filename().string();
	}

	const std::string FileSystem::GetFileName(const std::string& filepath)
	{
		return fs::path(filepath).filename().string();
	}

	std::filesystem::path FileSystem::OpenFileDialog(const char* filter /*= "All\0*.*\0"*/)
	{
		return {};
	}

	std::filesystem::path FileSystem::OpenFolderDialog(const char* initialFolder /*= ""*/)
	{
		return {};
	}

	std::filesystem::path FileSystem::SaveFileDialog(const char* filter /*= "All\0*.*\0"*/)
	{
		return {};
	}

	bool FileSystem::HasEnvironmentVariable(const std::string& key)
	{
		return false;
	}

	bool FileSystem::SetEnvironmentVariable(const std::string& key, const std::string& value)
	{
		return false;
	}

	std::string FileSystem::GetEnvironmentVariable(const std::string& key)
	{
		return {};
	}

}