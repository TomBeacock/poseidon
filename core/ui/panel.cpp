#include "panel.h"

#include "rendering/renderer2d.h"

#include <iostream>

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

	std::shared_ptr<Widget> Panel::hitTest(const Vec2& position)
	{
		if (!positionInRect(position))
			return nullptr;

		Vec2 relativePosition = position - actualPosition();
		for(auto& child : children_)
		{
			auto hitResult = child->hitTest(relativePosition);
			if (hitResult != nullptr)
				return hitResult;
		}
		return hitTestable() ? shared_from_this() : nullptr;
	}

	void Panel::addChild(std::shared_ptr<Widget> child)
	{
		if (auto parent = child->parent_.lock()) {
			std::cerr << "Trying to add a widget that already has a parent, remove it from it's parent first." << std::endl;
			parent->removeChild(child);
		}
		auto widget = shared_from_this();
		auto panel = std::static_pointer_cast<Panel>(widget);
		child->parent_ = panel;
		children_.push_back(child);
	}

	void Panel::addChild(std::shared_ptr<Widget> view, std::unique_ptr<LayoutParams> layoutParams)
	{
		view->setLayoutParams(std::move(layoutParams));
		addChild(view);
	}

	void Panel::removeChild(const std::shared_ptr<Widget>& child)
	{
		const auto it = std::find(children_.begin(), children_.end(), child);
		if (it != children_.end())
			children_.erase(it);
	}

	void Panel::onDraw(const Vec2& relativeOrigin)
	{
		Vec2 pos = actualPosition();
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