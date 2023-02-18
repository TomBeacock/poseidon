#include "compound_widget.h"

namespace poseidon
{
	CompoundWidget::CompoundWidget() :
		root_(nullptr) {}

	Vec2 CompoundWidget::onMeasure()
	{
		root_->measure();
		return root_->measuredSize();
	}

	void CompoundWidget::onLayout(const Vec2& position, const Vec2& size)
	{
		root_->layout(Vec2::zero, size);
	}

	void CompoundWidget::onDraw(const Vec2& relativeOrigin)
	{
		root_->draw(relativeOrigin + actualPosition());
	}
}