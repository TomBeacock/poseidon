#pragma once

#include <ostream>

namespace poseidon
{
	struct Vec2;
	struct Vec3;

	struct Vec4
	{
		float x;
		float y;
		float z;
		float w;

		Vec4();
		Vec4(float x, float y, float z, float w);

		static const Vec4 zero;
		static const Vec4 one;
		static const Vec4 identity;

		static float distance(const Vec4& lhs, const Vec4& rhs);
		static float dot(const Vec4& lhs, const Vec4& rhs);

		float sqrMagnitude() const;
		float magnitude() const;
		void normalize();
		Vec4 normalized() const;

		// Assignment operators
		Vec4& operator+=(const Vec4& rhs);
		Vec4& operator-=(const Vec4& rhs);
		Vec4& operator*=(float rhs);
		Vec4& operator/=(float rhs);

		// Conversion operators
		operator Vec2();
		operator Vec3();
	};

	// Unary operators
	Vec4 operator-(const Vec4& lhs);

	// Binary operators
	Vec4 operator+(const Vec4& lhs, const Vec4& rhs);
	Vec4 operator-(const Vec4& lhs, const Vec4& rhs);
	Vec4 operator*(const Vec4& lhs, float rhs);
	Vec4 operator*(float lhs, const Vec4& rhs);
	Vec4 operator*(const Vec4& lhs, const Vec4& rhs);
	Vec4 operator/(const Vec4& lhs, float rhs);
	Vec4 operator/(float lhs, const Vec4& rhs);
	Vec4 operator/(const Vec4& lhs, const Vec4& rhs);

	// Print
	std::ostream& operator<<(std::ostream& outs, const Vec4& v);
}