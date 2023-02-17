#include "panel.h"

#include "rendering/renderer2d.h"

namespace poseidon
{
	Size::Size(float size) :
		size_(size), type_(Type::Exact) {}

	const Size Size::fill = Size(Type::Fill);
	const Size Size::wrap = Size(Type::Wrap);

	Size::Size(Type type) :
		size_(-1.0f), type_(type) {}

	LayoutParams::LayoutParams() :
		width_(Size::wrap), height_(Size::wrap){}

	LayoutParams::LayoutParams(const Size& width, const Size& height) :
		width_(width), height_(height) {}

	LayoutParams::LayoutParams(float width, float height) :
		width_(width), height_(height) {}

	LayoutParams::~LayoutParams() {}

	MarginLayoutParams::MarginLayoutParams() :
		LayoutParams() {}

	MarginLayoutParams::MarginLayoutParams(const Size& width, const Size& height) :
		LayoutParams(width, height) {}

	MarginLayoutParams::MarginLayoutParams(float width, float height) :
		LayoutParams(width, height) {}

	Panel::Panel() :
		padding_(), color_(1.0f, 1.0f, 1.0f, 1.0f) {}

	void Panel::addView(std::shared_ptr<View> view, std::unique_ptr<LayoutParams> layoutParams)
	{
		view->setLayoutParams(std::move(layoutParams));
		children_.push_back(view);
	}

	void Panel::onDraw(const Vec2& relativeOrigin)
	{
		Renderer2D::drawRect(Bounds(relativeOrigin + actualPosition(), actualSize()), color_);
		Vec2 newRelativeOrigin = relativeOrigin + actualPosition();
		for (auto& child : children_)
			child->draw(newRelativeOrigin);
	}

	void Panel::measureChildren()
	{
		for (auto& child : children_)
			child->measure();
	}

	void Panel::calculateChildArea(Vec2& position, Vec2& size)
	{
		position = Vec2(padding_.left, padding_.top);
		size = actualSize() - padding_.size();
	}
}