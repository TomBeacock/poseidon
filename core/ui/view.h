#pragma once

#include <memory>

#include "math/vec2.h"
#include "layout_params.h"

namespace poseidon
{
	enum class HorizontalAlignment { Left, Center, Right };
	enum class VerticalAlignment { Top, Center, Bottom };

	class View
	{
	public:
		View();
		virtual ~View();

		void draw(const Vec2& relativeOrigin);
		void measure();
		void layout(float left, float right, float top, float bottom);

		inline const Vec2& actualPosition() const { return position_; }
		inline const Vec2& actualSize() const { return size_; }

		inline float measuredWidth() const { return measuredSize_.x; }
		inline float measuredHeight() const { return measuredSize_.y; }

		inline const Vec2& measuredSize() const { return measuredSize_; }
		inline void setMeasuredSize(const Vec2& desiredSize) { measuredSize_ = desiredSize; }

		inline void setPreferredSize(const Vec2& preferredSize) { preferredSize_ = preferredSize; }

		inline LayoutParams& layoutParams() { return *layoutParams_; }
		inline void setLayoutParams(std::unique_ptr<LayoutParams> layoutParams) { layoutParams_ = std::move(layoutParams); }

	protected:
		virtual void onMeasure() = 0;
		virtual void onLayout(float left, float right, float top, float bottom) = 0;
		virtual void onDraw(const Vec2& relativeOrigin) = 0;

	private:
		Vec2 position_;
		Vec2 size_;
		Vec2 measuredSize_;
		Vec2 preferredSize_;
		std::unique_ptr<LayoutParams> layoutParams_;
	};
}