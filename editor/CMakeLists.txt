project("editor")

add_executable(editor
"main.cpp"
"editor.h" "editor.cpp"
"sandbox_layer.h" "sandbox_layer.cpp")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_link_libraries(editor
	core
	SDL2::SDL2
	SDL2_image::SDL2_image
	SDL2::SDL2main
)

target_include_directories(editor PUBLIC "${CMAKE_SOURCE_DIR}/core/include")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET editor PROPERTY CXX_STANDARD 20)
endif()