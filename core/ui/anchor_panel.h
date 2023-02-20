#pragma once

#include "panel.h"

namespace poseidon
{
	struct Vec2;

	class AnchorPanel : public Panel
	{
		class LayoutParams : poseidon::LayoutParams
		{
		public:
			LayoutParams();
			LayoutParams(const Size& width, const Size& height, float x, float y);
			LayoutParams(float width, float height, float x, float y);

			inline float x() const { return x_; }
			inline float y() const { return y_; }
			inline Vec2 position() const { return { x_, y_ }; }
			inline void setX(float x) { x_ = x; }
			inline void setY(float y) { y_ = y; }
			inline void setPosition(Vec2 position) { x_ = position.x; y_ = position.y; }

		private:
			float x_;
			float y_;
		};

	protected:
		virtual Vec2 onMeasure() override;
		virtual void onLayout(const Vec2& position, const Vec2& size) override;
	};
}