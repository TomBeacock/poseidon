#include "view.h"

#include "panel.h"

#include "math/vec3.h"

namespace poseidon
{
	View::View() :
		position_(0.0f, 0.0f), size_(0.0f, 0.0f),
		measuredSize_(0.0f, 0.0f),
		layoutParams_(std::make_unique<LayoutParams>()) {}

	View::~View() = default;

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

	const LayoutParams& View::layoutParams() const
	{
		return *layoutParams_;
	}

	LayoutParams& View::layoutParams()
	{
		return *layoutParams_;
	}

	void View::setLayoutParams(std::unique_ptr<LayoutParams> layoutParams)
	{
		layoutParams_ = std::move(layoutParams);
	}
}