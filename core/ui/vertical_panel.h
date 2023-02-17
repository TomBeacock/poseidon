#pragma once

#include "panel.h"

namespace poseidon
{
	class VerticalPanel : public Panel
	{
	public:
		class LayoutParams : public MarginLayoutParams
		{
		public:
			LayoutParams();
			LayoutParams(const Size& width, const Size& height);
			LayoutParams(float width, float height);

			inline const HorizontalAlignment& horizontalAlignment() const { return horizontalAlignment_; }
			inline void setHorizontalAlignment(const HorizontalAlignment& alignment) { horizontalAlignment_ = alignment; }

		private:
			HorizontalAlignment horizontalAlignment_;
		};

	protected:
		virtual Vec2 onMeasure() override;
		virtual void onLayout(const Vec2& position, const Vec2& size) override;
	};
}