#pragma once

#include <Renderer/Shader.hpp>
#include <Glad/glad.h>

namespace Vertex 
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::filesystem::path& filepath);

		virtual void Bind() override;
		virtual void Unbind() const override;

		virtual void SetInt(const std::string& name, int value) override;
		virtual void SetIntArray(const std::string& name, int* values, uint32_t count) override;
		virtual void SetFloat(const std::string& name, float value) override;
		virtual void SetFloat2(const std::string& name, const Vector2<float>& value) override;
		virtual void SetFloat3(const std::string& name, const Vector3<float>& value) override;
		virtual void SetFloat4(const std::string& name, const Vector4<float>& value) override;

		virtual const std::string& GetName() const override { return m_Name; }
	private:
		void UploadUniformInt(const std::string& name, int value);
		void UploadUniformIntArray(const std::string& name, int* values, uint32_t count);

		void UploadUniformFloat(const std::string& name, float value);
		void UploadUniformFloat2(const std::string& name, const Vector2<float>& value);
		void UploadUniformFloat3(const std::string& name, const Vector3<float>& value);
		void UploadUniformFloat4(const std::string& name, const Vector4<float>& value);
	private:
		void ReadShaderFromFile(const std::filesystem::path& filepath);
		void CompileAndUploadShader();
		static GLenum ShaderTypeFromString(const std::string& type);
	private:
		RendererID m_RendererID;

		std::string m_ShaderSource;

		std::filesystem::path m_FilePath;
		std::string m_Name;
	};

}
