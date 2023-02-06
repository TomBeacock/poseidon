#include "editor.h"

#include <memory>

#include "sandbox_layer.h"

namespace editor
{
	Editor::Editor()
	{
		addLayer(std::make_unique<SandboxLayer>());
	}
}