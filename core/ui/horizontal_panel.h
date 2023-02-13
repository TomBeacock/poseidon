#pragma once

#include "panel.h"

namespace poseidon
{
	class HorizontalPanel : public Panel
	{
	protected:
		virtual void onMeasure() override;
		virtual void onLayout(float left, float right, float top, float bottom) override;
	};
}