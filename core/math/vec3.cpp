#include "Vec3.h"

#include <cmath>

#include "vec2.h"
#include "vec4.h"

namespace poseidon
{
	Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

	const Vec3 Vec3::zero = Vec3(0.0f, 0.0f, 0.0f);
	const Vec3 Vec3::one = Vec3(1.0f, 1.0f, 1.0f);
	const Vec3 Vec3::right = Vec3(1.0f, 0.0f, 0.0f);
	const Vec3 Vec3::left = Vec3(-1.0f, 0.0f, 0.0f);
	const Vec3 Vec3::up = Vec3(0.0f, 1.0f, 0.0f);
	const Vec3 Vec3::down = Vec3(0.0f, -1.0f, 0.0f);
	const Vec3 Vec3::forward = Vec3(0.0f, 0.0f, 1.0f);
	const Vec3 Vec3::backward = Vec3(0.0f, 0.0f, -1.0f);

	float Vec3::distance(const Vec3& lhs, const Vec3& rhs)
	{
		return (lhs - rhs).magnitude();
	}

	float Vec3::dot(const Vec3& lhs, const Vec3& rhs)
	{
		return
			lhs.x * rhs.x +
			lhs.y * rhs.y +
			lhs.z * rhs.z;
	}

	Vec3 Vec3::cross(const Vec3& lhs, const Vec3& rhs)
	{
		return Vec3(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x
		);
	}

	float Vec3::sqrMagnitude() const
	{
		return
			this->x * this->x +
			this->y * this->y +
			this->z * this->z;
	}

	float Vec3::magnitude() const
	{
		return sqrt(sqrMagnitude());
	}

	void Vec3::normalize()
	{
		float mag = magnitude();
		if(mag == 0.0f) { return; }

		float scale = 1.0f / mag;
		this->x *= scale;
		this->y *= scale;
		this->z *= scale;
	}

	Vec3 Vec3::normalized() const
	{
		float mag = magnitude();
		if (mag == 0.0f) { return zero; }

		float scale = 1.0f / mag;
		return Vec3(
			this->x * scale,
			this->y * scale,
			this->z * scale
		);
	}

	Vec3& Vec3::operator+=(const Vec3& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		return *this;
	}

	Vec3& Vec3::operator-=(const Vec3& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return *this;
	}

	Vec3& Vec3::operator*=(float rhs)
	{
		this->x *= rhs;
		this->y *= rhs;
		this->z *= rhs;
		return *this;
	}

	Vec3& Vec3::operator/=(float rhs)
	{
		this->x /= rhs;
		this->y /= rhs;
		this->z /= rhs;
		return *this;
	}

	Vec3::operator Vec2()
	{
		return Vec2(x, y);
	}

	Vec3::operator Vec4()
	{
		return Vec4(x, y, 0.0f, 0.0f);
	}

	Vec3 operator-(const Vec3& lhs)
	{
		return Vec3(-lhs.x, -lhs.y, -lhs.z);
	}

	Vec3 operator+(const Vec3& lhs, const Vec3& rhs)
	{
		return Vec3(
			lhs.x + rhs.x,
			lhs.y + rhs.y,
			lhs.z + rhs.z
		);
	}

	Vec3 operator-(const Vec3& lhs, const Vec3& rhs)
	{
		return Vec3(
			lhs.x - rhs.x,
			lhs.y - rhs.y,
			lhs.z - rhs.z
		);
	}

	Vec3 operator*(const Vec3& lhs, float rhs)
	{
		return Vec3(
			lhs.x * rhs,
			lhs.y * rhs,
			lhs.z * rhs
		);
	}

	Vec3 operator*(float lhs, const Vec3& rhs)
	{
		return Vec3(
			lhs * rhs.x,
			lhs * rhs.y,
			lhs * rhs.z
		);
	}

	Vec3 operator*(const Vec3& lhs, const Vec3& rhs)
	{
		return Vec3(
			lhs.x * rhs.x,
			lhs.y * rhs.y,
			lhs.z * rhs.z
		);
	}

	Vec3 operator/(const Vec3& lhs, float rhs)
	{
		return Vec3(
			lhs.x / rhs,
			lhs.y / rhs,
			lhs.z / rhs
		);
	}

	Vec3 operator/(float lhs, const Vec3& rhs)
	{
		return Vec3(
			lhs / rhs.x,
			lhs / rhs.y,
			lhs / rhs.z
		);
	}

	Vec3 operator/(const Vec3& lhs, const Vec3& rhs)
	{
		return Vec3(
			lhs.x / rhs.x,
			lhs.y / rhs.y,
			lhs.z / rhs.z
		);
	}

	std::ostream& operator<<(std::ostream& outs, const Vec3& v)
	{
		return outs << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	}
}