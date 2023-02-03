project("editor")

find_package(SDL2 REQUIRED)

add_executable(editor "editor.cpp")

target_include_directories(editor PUBLIC "${CMAKE_SOURCE_DIR}/core")
target_link_libraries(editor core SDL2::SDL2 SDL2::SDL2main)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET editor PROPERTY CXX_STANDARD 20)
endif()