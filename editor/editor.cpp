#include "editor.h"

#include <memory>

#include "sandbox_layer.h"
#include "editor_canvas.h"

namespace editor
{
	Editor::Editor()
	{
		addLayer(std::make_unique<EditorCanvas>());
		addLayer(std::make_unique<SandboxLayer>());
	}
}