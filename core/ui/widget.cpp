#include "widget.h"

#include "panel.h"

#include "math/vec3.h"

namespace poseidon
{
	Widget::Widget() :
		position_(0.0f, 0.0f), size_(0.0f, 0.0f),
		measuredSize_(0.0f, 0.0f),
		layoutParams_(std::make_unique<LayoutParams>()) {}

	Widget::~Widget() = default;

	void Widget::draw(const Vec2& relativeOrigin)
	{
		onDraw(relativeOrigin);
	}

	void Widget::measure()
	{
		measuredSize_ = onMeasure();
	}

	void Widget::layout(const Vec2& position, const Vec2& size)
	{
		position_ = position;
		size_ = size;
		onLayout(position, size);
	}

	const LayoutParams& Widget::layoutParams() const
	{
		return *layoutParams_;
	}

	LayoutParams& Widget::layoutParams()
	{
		return *layoutParams_;
	}

	void Widget::setLayoutParams(std::unique_ptr<LayoutParams> layoutParams)
	{
		layoutParams_ = std::move(layoutParams);
	}
}