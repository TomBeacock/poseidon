#pragma once

namespace poseidon
{
	struct Vec3;
	struct Vec4;

	struct Mat4
	{
	private:
		float values[4 * 4];

	public:
		Mat4(
			float m00, float m10, float m20, float m30,
			float m01, float m11, float m21, float m31,
			float m02, float m12, float m22, float m32,
			float m03, float m13, float m23, float m33
		);

		static const Mat4 zero;
		static const Mat4 one;
		static const Mat4 identity;

		static Mat4 translation(const Vec3& translation);
		static Mat4 rotation(float yaw, float pitch, float roll);
		static Mat4 scale(const Vec3& scale);
		static Mat4 transformation(const Vec3& translation, const Vec3& rotation, const Vec3& scale);
		static Mat4 orthographic(float width, float height, float near = -1.0f, float far = 1.0f);
		static Mat4 orthographic(float left, float right, float top, float bottom, float near = -1.0f, float far = 1.0f);
		static Mat4 perspective(float fov, float aspect, float near = -1.0f, float far = 1.0f);

		inline float operator()(unsigned int x, unsigned int y) const;

		// Assignment operators
		Mat4& operator+=(const Mat4& rhs);
		Mat4& operator-=(const Mat4& rhs);
		Mat4& operator*=(float rhs);
		Mat4& operator*=(const Mat4& rhs);
		Mat4& operator/=(float rhs);

		// Unary operators
		friend Mat4 operator-(const Mat4& lhs);

		// Binary operators
		friend Mat4 operator+(const Mat4& lhs, const Mat4& rhs);
		friend Mat4 operator-(const Mat4& lhs, const Mat4& rhs);
		friend Mat4 operator*(const Mat4& lhs, float rhs);
		friend Mat4 operator*(float lhs, const Mat4& rhs);
		friend Mat4 operator*(const Mat4& lhs, const Mat4& rhs);
		friend Vec4 operator*(const Mat4& lhs, const Vec4& rhs);
		friend Mat4 operator/(const Mat4& lhs, float rhs);
		friend Mat4 operator/(float lhs, const Mat4& rhs);
	};

	// Unary operators
	Mat4 operator-(const Mat4& lhs);

	// Binary operators
	Mat4 operator+(const Mat4& lhs, const Mat4& rhs);
	Mat4 operator-(const Mat4& lhs, const Mat4& rhs);
	Mat4 operator*(const Mat4& lhs, float rhs);
	Mat4 operator*(float lhs, const Mat4& rhs);
	Mat4 operator*(const Mat4& lhs, const Mat4& rhs);
	Vec4 operator*(const Mat4& lhs, const Vec4& rhs);
	Mat4 operator/(const Mat4& lhs, float rhs);
	Mat4 operator/(float lhs, const Mat4& rhs);
}