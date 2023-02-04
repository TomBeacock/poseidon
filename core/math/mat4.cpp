#include "mat4.h"

#include <cmath>

#include "vec3.h"
#include "vec4.h"

namespace poseidon
{
	Mat4::Mat4(
		float m00, float m10, float m20, float m30,
		float m01, float m11, float m21, float m31,
		float m02, float m12, float m22, float m32,
		float m03, float m13, float m23, float m33
	) : values {
		m00, m01, m02, m03,
		m10, m11, m12, m13,
		m20, m21, m22, m23,
		m30, m31, m32, m33
	}
	{

	}

	const Mat4 Mat4::zero = Mat4(
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f
	);
	const Mat4 Mat4::one = Mat4(
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f
	);
	const Mat4 Mat4::identity = Mat4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	Mat4 Mat4::translation(const Vec3& translation)
	{
		return Mat4(
			1.0f, 0.0f, 0.0f, translation.x,
			0.0f, 1.0f, 0.0f, translation.y,
			0.0f, 0.0f, 1.0f, translation.z,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}

	Mat4 Mat4::rotation(float yaw, float pitch, float roll)
	{
		float sinYaw = sin(yaw), cosYaw = cos(yaw);
		float sinPitch = sin(pitch), cosPitch = cos(pitch);
		float sinRoll = sin(roll), cosRoll = cos(roll);
		return Mat4(
			cosYaw * cosRoll + sinYaw * sinPitch * sinRoll,
			sinYaw * sinPitch * cosRoll - cosYaw * sinRoll,
			sinYaw * cosPitch,
			0.0f,
			cosPitch * sinRoll,
			cosPitch * cosRoll,
			-sinPitch,
			0.0f,
			cosYaw * sinPitch * sinRoll - sinYaw * cosRoll,
			sinYaw * sinRoll + cosYaw * sinPitch * cosRoll,
			cosYaw * cosPitch,
			0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}

	Mat4 Mat4::scale(const Vec3& scale)
	{
		return Mat4(
			scale.x, 0.0f, 0.0f, 0.0f,
			0.0f, scale.y, 0.0f, 0.0f,
			0.0f, 0.0f, scale.z, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}

	Mat4 Mat4::transformation(const Vec3& translation, const Vec3& rotation, const Vec3& scale)
	{
		return
			Mat4::translation(translation) *
			Mat4::rotation(rotation.y, rotation.x, rotation.z) *
			Mat4::scale(scale);
	}

	Mat4 Mat4::orthographic(float width, float height, float near, float far)
	{
		float halfWidth = width / 2.0f;
		float halfHeight = height / 2.0f;
		return Mat4::orthographic(
			-halfWidth, halfWidth,
			halfHeight, -halfHeight,
			near, far);
	}

	Mat4 Mat4::orthographic(float left, float right, float top, float bottom, float near, float far)
	{
		float range = 1.0f / (far - near);
		return Mat4(
			2.0f / (right - left), 0.0f, 0.0f, (left + right) / (left - right),
			0.0f, 2.0f / (top - bottom), 0.0f, (top + bottom) / (bottom - top),
			0.0f, 0.0f, range, -near * range,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}

	Mat4 Mat4::perspective(float fov, float aspect, float near, float far)
	{
		float yScale = 1.0f / tan(fov * 0.5f);
		float q = far / (far - near);
		return Mat4(
			yScale / aspect, 0.0f, 0.0f, 0.0f,
			0.0f, yScale, 0.0f, 0.0f,
			0.0f, 0.0f, q, -q * near,
			0.0f, 0.0f, 1.0f, 1.0f
		);
	}

	float Mat4::operator()(unsigned int x, unsigned int y) const
	{
		return this->values[x * 4 + y];
	}

	Mat4& Mat4::operator+=(const Mat4& rhs)
	{
		for(int i = 0; i < 4 * 4; ++i)
			this->values[i] += rhs.values[i];
		return *this;
	}

	Mat4& Mat4::operator-=(const Mat4& rhs)
	{
		for (int i = 0; i < 4 * 4; ++i)
			this->values[i] -= rhs.values[i];
		return *this;
	}

	Mat4& Mat4::operator*=(float rhs)
	{
		for (int i = 0; i < 4 * 4; ++i)
			this->values[i] *= rhs;
		return *this;
	}

	Mat4& Mat4::operator*=(const Mat4& rhs)
	{
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				this->values[j * 4 + i] =
					(*this)(0, i) * rhs(j, 0) +
					(*this)(1, i) * rhs(j, 1) +
					(*this)(2, i) * rhs(j, 2) +
					(*this)(3, i) * rhs(j, 3);
			}
		}
		return *this;
	}

	Mat4& Mat4::operator/=(float rhs)
	{
		for (int i = 0; i < 4 * 4; ++i)
			this->values[i] /= rhs;
		return *this;
	}

	Mat4 operator-(const Mat4& lhs)
	{
		Mat4 result = lhs;
		for (int i = 0; i < 4 * 4; ++i)
			result.values[i] = -lhs.values[i];
		return result;
	}

	Mat4 operator+(const Mat4& lhs, const Mat4& rhs)
	{
		Mat4 result = lhs;
		for (int i = 0; i < 4 * 4; ++i)
			result.values[i] += rhs.values[i];
		return result;
	}

	Mat4 operator-(const Mat4& lhs, const Mat4& rhs)
	{
		Mat4 result = lhs;
		for (int i = 0; i < 4 * 4; ++i)
			result.values[i] -= rhs.values[i];
		return result;
	}

	Mat4 operator*(const Mat4& lhs, float rhs)
	{
		Mat4 result = lhs;
		for (int i = 0; i < 4 * 4; ++i)
			result.values[i] *= rhs;
		return result;
	}

	Mat4 operator*(float lhs, const Mat4& rhs)
	{
		Mat4 result = rhs;
		for (int i = 0; i < 4 * 4; ++i)
			result.values[i] *= lhs;
		return result;
	}

	Mat4 operator*(const Mat4& lhs, const Mat4& rhs)
	{
		Mat4 result = Mat4::zero;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				result.values[j * 4 + i] =
					lhs(0, i) * rhs(j, 0) +
					lhs(1, i) * rhs(j, 1) +
					lhs(2, i) * rhs(j, 2) +
					lhs(3, i) * rhs(j, 3);
			}
		}
		return result;
	}

	Vec4 operator*(const Mat4& lhs, const Vec4& rhs)
	{
		return Vec4(
			lhs(0, 0) * rhs.x + lhs(1, 0) * rhs.y + lhs(2, 0) * rhs.z + lhs(3, 0) * rhs.w,
			lhs(0, 1) * rhs.x + lhs(1, 1) * rhs.y + lhs(2, 1) * rhs.z + lhs(3, 1) * rhs.w,
			lhs(0, 2) * rhs.x + lhs(1, 2) * rhs.y + lhs(2, 2) * rhs.z + lhs(3, 2) * rhs.w,
			lhs(0, 3) * rhs.x + lhs(1, 3) * rhs.y + lhs(2, 3) * rhs.z + lhs(3, 3) * rhs.w
		);
	}

	Mat4 operator/(const Mat4& lhs, float rhs)
	{
		Mat4 result = lhs;
		for (int i = 0; i < 4 * 4; ++i)
			result.values[i] /= rhs;
		return result;
	}

	Mat4 operator/(float lhs, const Mat4& rhs)
	{
		Mat4 result = rhs;
		for (int i = 0; i < 4 * 4; ++i)
			result.values[i] /= lhs;
		return result;
	}
}