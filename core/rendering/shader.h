#pragma once

#include <string>

namespace poseidon
{
	struct Vec2;
	struct Vec3;
	struct Vec4;
	struct Mat4;

	class Shader
	{
	public:
		Shader(const std::string& vertexSource, const std::string& fragmentSource);
		~Shader();

		void bind() const;
		void unbind() const;

		void setInt(const char* name, int value) const;
		void setFloat(const char* name, float value) const;
		void setVec2(const char* name, const Vec2& value) const;
		void setVec3(const char* name, const Vec3& value) const;
		void setVec4(const char* name, const Vec4& value) const;
		void setMat4(const char* name, const Mat4& value) const;
		void setBool(const char* name, bool value) const;

	private:
		uint32_t id_;
	};
}