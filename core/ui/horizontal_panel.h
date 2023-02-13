#pragma once

#include "panel.h"

namespace poseidon
{
	class HorizontalPanel : public Panel
	{
	protected:
		virtual void onMeasure() override;
		virtual void onLayout(const Vec2& position, const Vec2& size) override;
	};
}