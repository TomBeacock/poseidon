#pragma once

#include <vector>
#include <memory>

#include "view.h"

namespace poseidon
{
	class Panel : public View
	{
	public:
		virtual void onDraw() final;

		inline const std::vector<std::shared_ptr<View>> children() const { return children_; }

	protected:
		void measureChildren();

	private:
		std::vector<std::shared_ptr<View>> children_;
	};
}