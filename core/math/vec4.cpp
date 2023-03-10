#include "Vec4.h"

#include <cmath>

#include "vec2.h"
#include "vec3.h"

namespace poseidon
{
	Vec4::Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
	Vec4::Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	const Vec4 Vec4::zero = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
	const Vec4 Vec4::one = Vec4(1.0f, 1.0f, 1.0f, 1.0f);
	const Vec4 Vec4::identity = Vec4(0.0f, 0.0f, 0.0f, 1.0f);

	float Vec4::distance(const Vec4& lhs, const Vec4& rhs)
	{
		return (lhs - rhs).magnitude();
	}

	float Vec4::dot(const Vec4& lhs, const Vec4& rhs)
	{
		return
			lhs.x * rhs.x +
			lhs.y * rhs.y +
			lhs.z * rhs.z +
			lhs.w * rhs.w;
	}

	float Vec4::sqrMagnitude() const
	{
		return
			this->x * this->x +
			this->y * this->y +
			this->z * this->z +
			this->w * this->w;
	}

	float Vec4::magnitude() const
	{
		return sqrt(sqrMagnitude());
	}

	void Vec4::normalize()
	{
		float mag = magnitude();
		if(mag == 0.0f) { return; }

		float scale = 1.0f / mag;
		this->x *= scale;
		this->y *= scale;
		this->z *= scale;
		this->w *= scale;
	}

	Vec4 Vec4::normalized() const
	{
		float mag = magnitude();
		if (mag == 0.0f) { return zero; }

		float scale = 1.0f / mag;
		return Vec4(
			this->x * scale,
			this->y * scale,
			this->z * scale,
			this->w * scale
		);
	}

	Vec4& Vec4::operator+=(const Vec4& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		this->w += rhs.w;
		return *this;
	}

	Vec4& Vec4::operator-=(const Vec4& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		this->w -= rhs.w;
		return *this;
	}

	Vec4& Vec4::operator*=(float rhs)
	{
		this->x *= rhs;
		this->y *= rhs;
		this->z *= rhs;
		this->w *= rhs;
		return *this;
	}

	Vec4& Vec4::operator/=(float rhs)
	{
		this->x /= rhs;
		this->y /= rhs;
		this->z /= rhs;
		this->w /= rhs;
		return *this;
	}

	Vec4::operator Vec2()
	{
		return Vec2(x, y);
	}

	Vec4::operator Vec3()
	{
		return Vec3(x, y, z);
	}

	Vec4 operator-(const Vec4& lhs)
	{
		return Vec4(-lhs.x, -lhs.y, -lhs.z, -lhs.w);
	}

	Vec4 operator+(const Vec4& lhs, const Vec4& rhs)
	{
		return Vec4(
			lhs.x + rhs.x,
			lhs.y + rhs.y,
			lhs.z + rhs.z,
			lhs.w + rhs.w
		);
	}

	Vec4 operator-(const Vec4& lhs, const Vec4& rhs)
	{
		return Vec4(
			lhs.x - rhs.x,
			lhs.y - rhs.y,
			lhs.z - rhs.z,
			lhs.w - rhs.w
		);
	}

	Vec4 operator*(const Vec4& lhs, float rhs)
	{
		return Vec4(
			lhs.x * rhs,
			lhs.y * rhs,
			lhs.z * rhs,
			lhs.w * rhs
		);
	}

	Vec4 operator*(float lhs, const Vec4& rhs)
	{
		return Vec4(
			lhs * rhs.x,
			lhs * rhs.y,
			lhs * rhs.z,
			lhs * rhs.w
		);
	}

	Vec4 operator*(const Vec4& lhs, const Vec4& rhs)
	{
		return Vec4(
			lhs.x * rhs.x,
			lhs.y * rhs.y,
			lhs.z * rhs.z,
			lhs.w * rhs.w
		);
	}

	Vec4 operator/(const Vec4& lhs, float rhs)
	{
		return Vec4(
			lhs.x / rhs,
			lhs.y / rhs,
			lhs.z / rhs,
			lhs.w / rhs
		);
	}

	Vec4 operator/(float lhs, const Vec4& rhs)
	{
		return Vec4(
			lhs / rhs.x,
			lhs / rhs.y,
			lhs / rhs.z,
			lhs / rhs.w
		);
	}

	Vec4 operator/(const Vec4& lhs, const Vec4& rhs)
	{
		return Vec4(
			lhs.x / rhs.x,
			lhs.y / rhs.y,
			lhs.z / rhs.z,
			lhs.w / rhs.w
		);
	}

	std::ostream& operator<<(std::ostream& outs, const Vec4& v)
	{
		return outs << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
	}
}