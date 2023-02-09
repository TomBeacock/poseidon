#include "view.h"

namespace poseidon
{
	void View::draw()
	{
		onDraw();
	}

	void View::measure()
	{
		onMeasure();
	}

	void View::layout(float left, float right, float top, float bottom)
	{
		position_ = Vec2(left, top);
		size_ = Vec2(right - left, bottom - top);
		onLayout(left, right, top, bottom);
	}
}