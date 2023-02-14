#pragma once

#include <vector>
#include <memory>

#include "view.h"

namespace poseidon
{
	class Panel : public View
	{
	public:
		Panel();

		inline const std::vector<std::shared_ptr<View>>& children() const { return children_; }
		inline void addView(std::shared_ptr<View> view) { children_.push_back(view); }

		inline const Thickness& padding() const { return padding_; }
		inline void setPadding(const Thickness& padding) { padding_ = padding; }

	protected:
		virtual void onDraw(const Vec2& relativeOrigin) final;

		void measureChildren();
		void calculateChildArea(Vec2& position, Vec2& size);

	private:
		std::vector<std::shared_ptr<View>> children_;
		Thickness padding_;
	};
}