project("core")

add_library (core
"include/poseidon/core.h"
"include/poseidon/events.h"
"include/poseidon/math.h"
"include/poseidon/rendering.h"
"include/poseidon/ui.h"

"system/application.h" "system/application.cpp"
"system/window.h" "system/window.cpp"
"system/layer.h"
"system/layer_stack.h" "system/layer_stack.cpp"

"input/key_codes.h" "input/key_codes.cpp"
"input/button_codes.h"

"events/event.h" 
"events/key_events.h" "events/key_events.cpp"
"events/mouse_events.h" "events/mouse_events.cpp"
"events/window_events.h" "events/window_events.cpp"

"math/vec2.h" "math/vec2.cpp"
"math/vec3.h" "math/vec3.cpp"
"math/vec4.h" "math/vec4.cpp"
"math/mat4.h" "math/mat4.cpp"

"rendering/renderer.h" "rendering/renderer.cpp"
"rendering/renderer2d.h" "rendering/renderer2d.cpp"
"rendering/array_buffer.h" "rendering/array_buffer.cpp"
"rendering/index_buffer.h" "rendering/index_buffer.cpp"
"rendering/vertex_array.h" "rendering/vertex_array.cpp"
"rendering/shader.h" "rendering/shader.cpp"
"rendering/texture.h" "rendering/texture.cpp"

"ui/canvas.h" "ui/canvas.cpp"
"ui/widget.h" "ui/widget.cpp"
"ui/panel.h" "ui/panel.cpp"
"ui/horizontal_panel.h" "ui/horizontal_panel.cpp"
"ui/vertical_panel.h" "ui/vertical_panel.cpp"
"ui/compound_widget.h" "ui/compound_widget.cpp"
"ui/button.h" "ui/button.cpp"
"ui/rectangle.h" "ui/rectangle.cpp" 
"ui/thickness.h" "ui/thickness.cpp"
"ui/font.h" "ui/font.cpp"
"ui/text.h" "ui/text.cpp"
"ui/anchor_panel.h" "ui/anchor_panel.cpp"

"util/utf8_iterator.h" "util/utf8_iterator.cpp"
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

set_property(TARGET core PROPERTY CXX_STANDARD 20)

target_link_libraries(core
	SDL2::SDL2
	SDL2_image::SDL2_image
	glad
	nlohmann_json::nlohmann_json
)

target_include_directories(core PUBLIC
"${PROJECT_SOURCE_DIR}"
"${PROJECT_SOURCE_DIR}/include"
"${SDL2_INCLUDE_DIR}"
"${SDL2_IMAGE_INCLUDE_DIRS}"
"${CMAKE_SOURCE_DIR}/extern/glad/include"
"${CMAKE_SOURCE_DIR}/extern/json/include"
)

target_compile_definitions(core PUBLIC RES_DIR="${CMAKE_SOURCE_DIR}/res/")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET core PROPERTY CXX_STANDARD 20)
endif()
