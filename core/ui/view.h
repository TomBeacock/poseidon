#pragma once

#include <memory>

#include "math/vec2.h"
#include "thickness.h"

namespace poseidon
{
	enum class HorizontalAlignment { Left, Center, Right, Fill };
	enum class VerticalAlignment { Top, Center, Bottom, Fill };

	class View
	{
	public:
		View();
		virtual ~View();

		void draw(const Vec2& relativeOrigin);
		void measure();
		void layout(const Vec2& position, const Vec2& size);

		inline const Vec2& actualPosition() const { return position_; }
		inline const Vec2& actualSize() const { return size_; }

		inline float measuredWidth() const { return measuredSize_.x; }
		inline float measuredHeight() const { return measuredSize_.y; }

		inline const Vec2& measuredSize() const { return measuredSize_; }

		inline bool autoWidth() const { return preferredSize_.x < 0.0f; }
		inline void setAutoWidth() { preferredSize_.x = -1.0f; }
		inline bool autoHeight() const { return preferredSize_.y < 0.0f; }
		inline void setAutoHeight() { preferredSize_.y = -1.0f; }

		inline float preferredWidth() const { return preferredSize_.x; }
		inline float preferredHeight() const { return preferredSize_.y; }
		inline const Vec2& preferredSize() const { return preferredSize_; }
		inline void setPreferredWidth(float width) { preferredSize_.x = width; }
		inline void setPreferredHeight(float height) { preferredSize_.y = height; }
		inline void setPreferredSize(const Vec2& preferredSize) { preferredSize_ = preferredSize; }

		inline const HorizontalAlignment& horizontalAlignment() const { return horizontalAlignment_; }
		inline void setHorizontalAlignment(HorizontalAlignment horizontalAlignment) { horizontalAlignment_ = horizontalAlignment; }

		inline const VerticalAlignment& verticalAlignment() const { return verticalAlignment_; }
		inline void setVerticalAlignment(VerticalAlignment verticalAlignment) { verticalAlignment_ = verticalAlignment; }

		inline const Thickness& margin() const { return margin_; }
		inline void setMargin(const Thickness& margin) { margin_ = margin; }

	protected:
		virtual const Vec2& onMeasure() = 0;
		virtual void onLayout(const Vec2& position, const Vec2& size) = 0;
		virtual void onDraw(const Vec2& relativeOrigin) = 0;

	private:
		Vec2 position_;
		Vec2 size_;
		Vec2 measuredSize_;
		Vec2 preferredSize_;
		HorizontalAlignment horizontalAlignment_;
		VerticalAlignment verticalAlignment_;
		Thickness margin_;
	};
}