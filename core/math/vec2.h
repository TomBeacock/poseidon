#pragma once

#include <ostream>

namespace poseidon
{
	struct Vec3;
	struct Vec4;

	struct Vec2
	{
		float x;
		float y;

		Vec2();
		Vec2(float x, float y);

		static const Vec2 zero;
		static const Vec2 one;
		static const Vec2 right;
		static const Vec2 left;
		static const Vec2 up;
		static const Vec2 down;

		static float distance(const Vec2& lhs, const Vec2& rhs);
		static float dot(const Vec2& lhs, const Vec2& rhs);

		float sqrMagnitude() const;
		float magnitude() const;
		void normalize();
		Vec2 normalized() const;

		// Assignment operators
		Vec2& operator += (const Vec2& rhs);
		Vec2& operator -= (const Vec2& rhs);
		Vec2& operator *= (float rhs);
		Vec2& operator /= (float rhs);

		// Conversion operators
		operator Vec3();
		operator Vec4();
	};

	// Unary operators
	Vec2 operator - (const Vec2& lhs);

	// Binary operators
	Vec2 operator+(const Vec2& lhs, const Vec2& rhs);
	Vec2 operator-(const Vec2& lhs, const Vec2& rhs);
	Vec2 operator*(const Vec2& lhs, float rhs);
	Vec2 operator*(float lhs, const Vec2& rhs);
	Vec2 operator*(const Vec2& lhs, const Vec2& rhs);
	Vec2 operator/(const Vec2& lhs, float rhs);
	Vec2 operator/(float lhs, const Vec2& rhs);
	Vec2 operator/(const Vec2& lhs, const Vec2& rhs);

	// Print
	std::ostream& operator<<(std::ostream& outs, const Vec2& v);
}