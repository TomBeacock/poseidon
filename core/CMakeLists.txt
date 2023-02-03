project("core")

find_package(SDL2 REQUIRED)

add_library (core "poseidon.cpp" "poseidon.h")

target_link_libraries(core SDL2::SDL2)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET core PROPERTY CXX_STANDARD 20)
endif()
