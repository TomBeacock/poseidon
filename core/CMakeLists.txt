project("core")

find_package(SDL2 REQUIRED)

add_library (core "poseidon.h" "system/application.h" "system/application.cpp")

target_link_libraries(core SDL2::SDL2 glad)
target_include_directories(core PUBLIC "${CMAKE_SOURCE_DIR}/extern/glad/include")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET core PROPERTY CXX_STANDARD 20)
endif()
