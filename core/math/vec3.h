#pragma once

#include <ostream>

namespace poseidon
{
	struct Vec3
	{
		float x;
		float y;
		float z;

		Vec3();
		Vec3(float x, float y, float z);

		static const Vec3 zero;
		static const Vec3 one;
		static const Vec3 right;
		static const Vec3 left;
		static const Vec3 up;
		static const Vec3 down;
		static const Vec3 forward;
		static const Vec3 backward;

		static float distance(const Vec3& lhs, const Vec3& rhs);
		static float dot(const Vec3& lhs, const Vec3& rhs);
		static Vec3 cross(const Vec3& lhs, const Vec3& rhs);

		float sqrMagnitude() const;
		float magnitude() const;
		void normalize();
		Vec3 normalized() const;

		// Assignment operators
		Vec3& operator+=(const Vec3& rhs);
		Vec3& operator-=(const Vec3& rhs);
		Vec3& operator*=(float rhs);
		Vec3& operator/=(float rhs);
	};

	// Unary operators
	Vec3 operator-(const Vec3& lhs);

	// Binary operators
	Vec3 operator+(const Vec3& lhs, const Vec3& rhs);
	Vec3 operator-(const Vec3& lhs, const Vec3& rhs);
	Vec3 operator*(const Vec3& lhs, float rhs);
	Vec3 operator*(float lhs, const Vec3& rhs);
	Vec3 operator*(const Vec3& lhs, const Vec3& rhs);
	Vec3 operator/(const Vec3& lhs, float rhs);
	Vec3 operator/(float lhs, const Vec3& rhs);
	Vec3 operator/(const Vec3& lhs, const Vec3& rhs);

	// Print
	std::ostream& operator<<(std::ostream& outs, const Vec3& v);
}