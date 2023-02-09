project("core")


add_library (core
"include/poseidon/core.h"
"include/poseidon/math.h"
"include/poseidon/rendering.h"
"include/poseidon/ui.h"
"system/application.h" "system/application.cpp"
"system/window.h" "system/window.cpp"
"system/layer.h"
"system/layer_stack.h" "system/layer_stack.cpp"
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
"ui/view.h"
  "ui/panel.h" "ui/panel.cpp" "ui/horizontal_panel.h" "ui/horizontal_panel.cpp" "ui/view.cpp")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_link_libraries(core
	SDL2::SDL2
	SDL2_image::SDL2_image
	glad
)

target_include_directories(core PUBLIC
"${PROJECT_SOURCE_DIR}"
"${SDL2_INCLUDE_DIR}"
"${SDL2_IMAGE_INCLUDE_DIRS}"
"${CMAKE_SOURCE_DIR}/extern/glad/include"
)

target_compile_definitions(core PUBLIC RES_DIR="${CMAKE_SOURCE_DIR}/res/")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET core PROPERTY CXX_STANDARD 20)
endif()
