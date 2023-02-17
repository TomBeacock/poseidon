#include "rectangle.h"

#include "rendering/renderer2d.h"
#include "math/vec4.h"
#include "panel.h"

namespace poseidon
{
	Vec2 Rectangle::onMeasure()
	{
		float width = layoutParams().width().type() == Size::Type::Exact ? layoutParams().width().size() : 0.0f;
		float height = layoutParams().height().type() == Size::Type::Exact ? layoutParams().height().size() : 0.0f;
		return Vec2(width, height);
	}

	void Rectangle::onLayout(const Vec2& position, const Vec2& size)
	{
		
	}

	void Rectangle::onDraw(const Vec2& relativeOrigin)
	{
		Renderer2D::drawRect(Bounds(relativeOrigin + actualPosition(), actualSize(), Vec2::zero), color_);
	}
}