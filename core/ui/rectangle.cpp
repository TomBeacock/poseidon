#include "rectangle.h"

#include "rendering/renderer2d.h"
#include "math/vec4.h"

namespace poseidon
{
	const Vec2& Rectangle::onMeasure()
	{
		return preferredSize();
	}

	void Rectangle::onLayout(const Vec2& position, const Vec2& size)
	{
		
	}

	void Rectangle::onDraw(const Vec2& relativeOrigin)
	{
		Renderer2D::drawRect(Bounds(relativeOrigin + actualPosition(), actualSize(), Vec2::zero), color_);
	}
}