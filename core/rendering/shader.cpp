#include "shader.h"

#include <glad/gl.h>
#include <fstream>
#include <sstream>
#include <iostream>

#include "math/vec2.h"
#include "math/vec3.h"
#include "math/vec4.h"
#include "math/mat4.h"

namespace poseidon
{
	Shader::Shader(const std::string& vertexFilepath, const std::string& fragmentFilepath)
	{
		int success;
		GLchar log[1024];

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		std::string vertexSource = readShader(vertexFilepath);
		const char* vertexSourcePtr = vertexSource.c_str();
		glShaderSource(vertexShader, 1, &vertexSourcePtr, nullptr);
		glCompileShader(vertexShader);

		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 1024, nullptr, log);
			std::cout << log << std::endl;
		}

		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		std::string fragmentSource = readShader(fragmentFilepath);
		const char* fragmentSourcePtr = fragmentSource.c_str();
		glShaderSource(fragmentShader, 1, &fragmentSourcePtr, nullptr);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 1024, nullptr, log);
			std::cout << log << std::endl;
		}

		id_ = glCreateProgram();
		glAttachShader(id_, vertexShader);
		glAttachShader(id_, fragmentShader);
		glLinkProgram(id_);

		glGetProgramiv(id_, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(id_, 1024, nullptr, log);
			std::cout << log << std::endl;
		}
	}

	Shader::~Shader()
	{
		glDeleteProgram(id_);
	}

	void Shader::bind() const
	{
		glUseProgram(id_);
	}

	void Shader::unbind() const
	{
		glUseProgram(0);
	}

	void Shader::setInt(const char* name, int value) const
	{
		GLint location = glGetUniformLocation(id_, name);
		glUniform1i(location, value);
	}

	void Shader::setIntArray(const char* name, int* values, uint32_t count) const
	{
		GLint location = glGetUniformLocation(id_, name);
		glUniform1iv(location, count, values);
	}

	void Shader::setFloat(const char* name, float value) const
	{
		GLint location = glGetUniformLocation(id_, name);
		glUniform1f(location, value);
	}

	void Shader::setVec2(const char* name, const Vec2& value) const
	{
		GLint location = glGetUniformLocation(id_, name);
		glUniform2f(location, value.x, value.y);
	}

	void Shader::setVec3(const char* name, const Vec3& value) const
	{
		GLint location = glGetUniformLocation(id_, name);
		glUniform3f(location, value.x, value.y, value.z);
	}

	void Shader::setVec4(const char* name, const Vec4& value) const
	{
		GLint location = glGetUniformLocation(id_, name);
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}

	void Shader::setMat4(const char* name, const Mat4& value) const
	{
		GLint location = glGetUniformLocation(id_, name);
		glUniformMatrix4fv(location, 1, GL_FALSE, value.values());
	}

	void Shader::setBool(const char* name, bool value) const
	{
		GLint location = glGetUniformLocation(id_, name);
		glUniform1i(location, value);
	}

	std::string Shader::readShader(const std::string& filepath)
	{
		std::ifstream file(filepath);
		std::stringstream ss;
		ss << file.rdbuf();
		return ss.str();
	}
}