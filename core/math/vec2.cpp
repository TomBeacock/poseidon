#include "Vec2.h"

#include <cmath>

namespace poseidon
{
	Vec2::Vec2(float x, float y) :
		x(x), y(y) {}

	const Vec2 Vec2::zero = Vec2(0.0f, 0.0f);
	const Vec2 Vec2::one = Vec2(1.0f, 1.0f);
	const Vec2 Vec2::right = Vec2(1.0f, 0.0f);
	const Vec2 Vec2::left = Vec2(-1.0f, 0.0f);
	const Vec2 Vec2::up = Vec2(0.0f, 1.0f);
	const Vec2 Vec2::down = Vec2(0.0f, -1.0f);

	float Vec2::distance(const Vec2& lhs, const Vec2& rhs)
	{
		return (lhs - rhs).magnitude();
	}

	float Vec2::dot(const Vec2& lhs, const Vec2& rhs)
	{
		return
			lhs.x * rhs.x +
			lhs.y * rhs.y;
	}

	float Vec2::sqrMagnitude() const
	{
		return
			this->x * this->x +
			this->y * this->y;
	}

	float Vec2::magnitude() const
	{
		return sqrt(sqrMagnitude());
	}

	void Vec2::normalize()
	{
		float mag = magnitude();
		if(mag == 0.0) { return; }

		float scale = 1.0 / mag;
		this->x *= scale;
		this->y *= scale;
	}

	Vec2 Vec2::normalized() const
	{
		float mag = magnitude();
		if (mag == 0.0) { return zero; }

		float scale = 1.0 / mag;
		return Vec2(
			this->x * scale,
			this->y * scale
		);
	}

	Vec2& Vec2::operator+=(const Vec2& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	}

	Vec2& Vec2::operator-=(const Vec2& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		return *this;
	}

	Vec2& Vec2::operator*=(float rhs)
	{
		this->x *= rhs;
		this->y *= rhs;
		return *this;
	}

	Vec2& Vec2::operator/=(float rhs)
	{
		this->x /= rhs;
		this->y /= rhs;
		return *this;
	}

	Vec2 operator-(const Vec2& lhs)
	{
		return Vec2(-lhs.x, -lhs.y);
	}

	Vec2 operator+(const Vec2& lhs, const Vec2& rhs)
	{
		return Vec2(
			lhs.x + rhs.x,
			lhs.y + rhs.y
		);
	}

	Vec2 operator-(const Vec2& lhs, const Vec2& rhs)
	{
		return Vec2(
			lhs.x - rhs.x,
			lhs.y - rhs.y
		);
	}

	Vec2 operator*(const Vec2& lhs, float rhs)
	{
		return Vec2(
			lhs.x * rhs,
			lhs.y * rhs
		);
	}

	Vec2 operator*(float lhs, const Vec2& rhs)
	{
		return Vec2(
			lhs * rhs.x,
			lhs * rhs.y
		);
	}

	Vec2 operator*(const Vec2& lhs, const Vec2& rhs)
	{
		return Vec2(
			lhs.x * rhs.x,
			lhs.y * rhs.y
		);
	}

	Vec2 operator/(const Vec2& lhs, float rhs)
	{
		return Vec2(
			lhs.x / rhs,
			lhs.y / rhs
		);
	}

	Vec2 operator/(float lhs, const Vec2& rhs)
	{
		return Vec2(
			lhs / rhs.x,
			lhs / rhs.y
		);
	}

	Vec2 operator/(const Vec2& lhs, const Vec2& rhs)
	{
		return Vec2(
			lhs.x / rhs.x,
			lhs.y / rhs.y
		);
	}
}