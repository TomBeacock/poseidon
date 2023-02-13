#pragma once

#include <vector>
#include <memory>

#include "view.h"

namespace poseidon
{
	class Panel : public View
	{
	public:
		inline const std::vector<std::shared_ptr<View>>& children() const { return children_; }
		inline void addView(std::shared_ptr<View> view) { children_.push_back(view); }

	protected:
		virtual void onDraw(const Vec2& relativeOrigin) final;

		void measureChildren();

	private:
		std::vector<std::shared_ptr<View>> children_;
	};
}