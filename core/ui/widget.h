#pragma once

#include <memory>

#include "math/vec2.h"
#include "thickness.h"

namespace poseidon
{
	class LayoutParams;

	enum class HorizontalAlignment { Left, Center, Right };
	enum class VerticalAlignment { Top, Center, Bottom };

	class Widget
	{
	public:
		Widget();
		virtual ~Widget();

		void draw(const Vec2& relativeOrigin);
		void measure();
		void layout(const Vec2& position, const Vec2& size);

		inline const Vec2& actualPosition() const { return position_; }
		inline const Vec2& actualSize() const { return size_; }

		inline float measuredWidth() const { return measuredSize_.x; }
		inline float measuredHeight() const { return measuredSize_.y; }

		inline const Vec2& measuredSize() const { return measuredSize_; }

		const LayoutParams& layoutParams() const;
		LayoutParams& layoutParams();
		void setLayoutParams(std::unique_ptr<LayoutParams> layoutParams);

	protected:
		virtual Vec2 onMeasure() = 0;
		virtual void onLayout(const Vec2& position, const Vec2& size) = 0;
		virtual void onDraw(const Vec2& relativeOrigin) = 0;

	private:
		Vec2 position_;
		Vec2 size_;
		Vec2 measuredSize_;
		std::unique_ptr<LayoutParams> layoutParams_;
	};
}