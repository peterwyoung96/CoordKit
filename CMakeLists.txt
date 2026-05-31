cmake_minimum_required(VERSION 3.20)
project(CoordKit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE COORDKIT_FILES 
     CONFIGURE_DEPENDS 
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(CoordKit
    ${COORDKIT_FILES}
)
target_include_directories(CoordKit PUBLIC include)

add_executable(example examples/basic_usage.cpp)
target_link_libraries(example CoordKit)