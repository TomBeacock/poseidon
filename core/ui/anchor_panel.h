#pragma once

#include "panel.h"
#include "math/vec2.h"

namespace poseidon
{
	struct Vec2;

	class AnchorPanel : public Panel
	{
	public:
		class LayoutParams : public poseidon::LayoutParams
		{
		public:
			LayoutParams();
			LayoutParams(const Size& width, const Size& height);
			LayoutParams(float width, float height);

			inline const Vec2& position() const { return position_; }
			inline void setPosition(const Vec2& position) { position_ = position; }

			inline const Vec2& pivot() const { return pivot_; }
			inline void setPivot(const Vec2& pivot) { pivot_ = pivot; }

			inline const Vec2& anchorMin() const { return anchorMin_; }
			inline void setAnchorMin(const Vec2& anchorMin) { anchorMin_ = anchorMin; }

			inline const Vec2& anchorMax() const { return anchorMax_; }
			inline void setAnchorMax(const Vec2& anchorMax) { anchorMax_ = anchorMax; }

			inline void setAnchor(const Vec2& anchor) { anchorMin_ = anchor; anchorMax_ = anchor; }

			inline const Thickness& offset() const { return offset_; }
			inline void setOffset(const Thickness& offset) { offset_ = offset; }

		private:
			Vec2 position_;
			Vec2 pivot_;
			Vec2 anchorMin_;
			Vec2 anchorMax_;
			Thickness offset_;
		};

	protected:
		virtual Vec2 onMeasure() override;
		virtual void onLayout(const Vec2& position, const Vec2& size) override;
	};
}