#pragma once

#include "math/vec2.h"

namespace poseidon
{
	class View
	{
	public:
		virtual void onMeasure() = 0;
		virtual void onLayout(float left, float right, float top, float bottom) = 0;
		virtual void onDraw() = 0;

		void draw();
		void measure();
		void layout(float left, float right, float top, float bottom);

		inline float measuredWidth() const { return size_.x; }
		inline float measuredHeight() const { return size_.y; }

		inline const Vec2& measuredSize() const { return desiredSize_; }
		inline void setDesiredSize(const Vec2& desiredSize) { desiredSize_ = desiredSize; }

	private:
		Vec2 position_;
		Vec2 size_;
		Vec2 desiredSize_;
	};
}