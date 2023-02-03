project("glad")

add_library(glad STATIC
"include/glad/gl.h"
"include/KHR/khrplatform.h"
"src/gl.c")

target_include_directories(glad PUBLIC "${PROJECT_SOURCE_DIR}/include")