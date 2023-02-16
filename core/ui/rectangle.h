#pragma once

#include "view.h"

#include "math/vec4.h"

namespace poseidon
{
	class Rectangle : public View
	{
	public:
		inline void setColor(const Vec4& color) { color_ = color; }

	protected:
		virtual const Vec2& onMeasure() override;
		virtual void onLayout(const Vec2& position, const Vec2& size) override;
		virtual void onDraw(const Vec2& relativeOrigin) override;

	private:
		Vec4 color_;
	};
}