#include "rectangle.h"

#include "rendering/renderer2d.h"
#include "math/vec4.h"

namespace poseidon
{
	void Rectangle::onMeasure()
	{
		
	}

	void Rectangle::onLayout(float left, float right, float top, float bottom)
	{
		
	}

	void Rectangle::onDraw(const Vec2& relativeOrigin)
	{
		Renderer2D::drawRect(Bounds(relativeOrigin + actualPosition(), actualSize(), { 0.0f, 0.0f }), color_);
	}
}