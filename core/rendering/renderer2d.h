#pragma once

namespace poseidon
{
	struct Vec2;
	struct Vec4;
	class Texture;

	struct Bounds
	{
		float left, right, top, bottom;

		Bounds(const Vec2& position, const Vec2& size);
		Bounds(const Vec2& position, const Vec2& size, const Vec2& pivot);
		Bounds(float left, float right, float top, float bottom);
	};

	class Renderer2D
	{
	public:
		static void init();

		static void drawRect(const Bounds& bounds, const Vec4& color);
		static void drawRect(const Bounds& bounds, const Bounds& uv, const Texture& texture, const Vec4& tint);
	};
}