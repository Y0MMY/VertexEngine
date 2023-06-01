#pragma once

#include "Renderer.hpp"

#include <string>
#include <filesystem>

namespace Vertex
{
	class Shader : public RefCounted
	{
	public:
		virtual void Bind() = 0;
		virtual void Unbind() const = 0;

		virtual void SetInt(const std::string& name, int value) = 0;
		virtual void SetIntArray(const std::string& name, int* values, uint32_t count) = 0;
		virtual void SetFloat(const std::string& name, float value) = 0;
		virtual void SetFloat2(const std::string& name, const Vector2<float>& value) = 0;
		virtual void SetFloat3(const std::string& name, const Vector3<float>& value) = 0;
		virtual void SetFloat4(const std::string& name, const Vector4<float>& value) = 0;

		virtual const std::string& GetName() const = 0;

		static Shader* Create(const std::filesystem::path& filepath);
	};

}
