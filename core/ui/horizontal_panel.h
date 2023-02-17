#pragma once

#include "panel.h"

namespace poseidon
{
	class HorizontalPanel : public Panel
	{
	public:
		class LayoutParams : public MarginLayoutParams
		{
		public:
			LayoutParams();
			LayoutParams(const Size& width, const Size& height);
			LayoutParams(float width, float height);

			inline const VerticalAlignment& verticalAlignment() const { return verticalAlignment_; }
			inline void setVerticalAlignment(const VerticalAlignment& alignment) { verticalAlignment_ = alignment; }

		private:
			VerticalAlignment verticalAlignment_;
		};

	protected:
		virtual Vec2 onMeasure() override;
		virtual void onLayout(const Vec2& position, const Vec2& size) override;
	};
}