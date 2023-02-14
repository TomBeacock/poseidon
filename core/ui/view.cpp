#include "view.h"

namespace poseidon
{
	View::View() :
		position_(0.0f, 0.0f), size_(0.0f, 0.0f),
		measuredSize_(0.0f, 0.0f), preferredSize_(-1.0f, -1.0f),
		horizontalAlignment_(HorizontalAlignment::Left),
		verticalAlignment_(VerticalAlignment::Top),
		margin_()
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
		measuredSize_ = onMeasure();
	}

	void View::layout(const Vec2& position, const Vec2& size)
	{
		position_ = position;
		size_ = size;
		onLayout(position, size);
	}
}