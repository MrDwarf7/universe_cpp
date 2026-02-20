cmake_minimum_required(VERSION 4.1)

project(universe_cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")

add_executable(${PROJECT_NAME}
    src/main.cpp

    src/model/model.cpp

    src/mui/mui.cpp

    src/universe/fast_rand.cpp
    src/universe/generator.cpp

    vendored/imgui/imgui.cpp
    vendored/imgui/imgui_draw.cpp
    vendored/imgui/imgui_demo.cpp
    vendored/imgui/imgui_tables.cpp
    vendored/imgui/imgui_widgets.cpp
    vendored/imgui/rlImGui.cpp
)

# Build it yourself, then link in as a static lib
target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendored/raylib/libraylib.a)

target_include_directories(${PROJECT_NAME} PRIVATE
    src
    src/model
    src/mui
    src/universe
    vendored/imgui
    vendored/raylib
)

