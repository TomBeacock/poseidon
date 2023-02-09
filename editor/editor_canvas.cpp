#include "editor_canvas.h"

using namespace poseidon;

namespace editor
{
	EditorCanvas::EditorCanvas()
	{
		auto root = std::make_shared<VisualElement>();
		setRoot(root);
	}
}