#pragma once

#include "panel.h"

namespace poseidon
{
	class VerticalPanel : public Panel
	{
	protected:
		virtual const Vec2& onMeasure() override;
		virtual void onLayout(const Vec2& position, const Vec2& size) override;
	};
}