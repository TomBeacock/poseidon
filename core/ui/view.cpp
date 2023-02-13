#include "view.h"

namespace poseidon
{
	View::View() :
		position_(0.0f, 0.0f), size_(0.0f, 0.0f),
		measuredSize_(0.0f, 0.0f), preferredSize_(0.0f, 0.0f),
		layoutParams_(nullptr)
	{

	}

	View::~View()
	{

	}

	void View::draw(const Vec2& relativeOrigin)
	{
		onDraw(relativeOrigin);
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