#include "visual_element.h"

#include "math/vec4.h"
#include "rendering/renderer2d.h"

namespace poseidon
{
	void VisualElement::layout()
	{

	}

	void VisualElement::paint()
	{
		Renderer2D::drawRect(Bounds(position, size), Vec4::one);
	}
}