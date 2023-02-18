#pragma once

#include "widget.h"

namespace poseidon
{
	class CompoundWidget : public Widget
	{
	protected:
		CompoundWidget();

		virtual Vec2 onMeasure() override;
		virtual void onLayout(const Vec2& position, const Vec2& size) override;
		virtual void onDraw(const Vec2& relativeOrigin) override;

		void setRoot(std::unique_ptr<Widget> root) { root_ = std::move(root); }

	private:
		std::unique_ptr<Widget> root_;
	};
}