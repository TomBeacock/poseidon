#pragma once

#include <optional>

#include "widget.h"

namespace poseidon
{
	class CompoundWidget : public Widget
	{
	public:
		virtual std::shared_ptr<Widget> hitTest(const Vec2& position) override;

	protected:
		CompoundWidget();

		virtual Vec2 onMeasure() override;
		virtual void onLayout(const Vec2& position, const Vec2& size) override;
		virtual void onDraw(const Vec2& relativeOrigin) override;

		Widget*const root() { return root_.get(); };
		void setRoot(std::shared_ptr<Widget> root) { root_ = root; }

	private:
		std::shared_ptr<Widget> root_;
	};
}