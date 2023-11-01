cmake_minimum_required(VERSION 3.22)

project(VisualSort VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# --------------------------------------------------------------------
# OpenGL Related Components needed for imGUI
# --------------------------------------------------------------------
find_package(OpenGL REQUIRED)
link_libraries (${OPENGL_LIBRARY})

# To be able to include the GLFW header from your code, you need to tell the compiler where to find it.
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/glfw-master)

# Once GLFW has been added to the project, the GLFW_LIBRARIES cache variable contains all link-time dependencies of GLFW
# as it is currently configured. To link against GLFW, link against them and the glfw target.
include_directories(${PROJECT_SOURCE_DIR}/lib/glfw-master/include)
message(STATUS "${GLFW_LIBRARIES}")
set(GLFW_STATIC_LIBRARIES "${GLFW_LIBRARIES}")

include_directories(${PROJECT_SOURCE_DIR}/lib/imgui)

add_library(imguiSrc
        lib/imgui/imgui.cpp lib/imgui/imgui.h lib/imgui/imconfig.h
        lib/imgui/imgui_demo.cpp lib/imgui/imgui_draw.cpp lib/imgui/imgui_tables.cpp lib/imgui/imgui_widgets.cpp
        lib/imgui/imgui_impl_glfw.cpp lib/imgui/imgui_impl_glfw.h lib/imgui/imgui_impl_opengl3.cpp lib/imgui/imgui_impl_opengl3.h
)

add_library(src GUI.cpp GUI.h)

add_executable(main main.cpp)

target_link_libraries(main imguiSrc src)

target_link_libraries (main ${GLEW_LIBRARIES})
target_link_libraries (main glfw ${GLFW_STATIC_LIBRARIES})

add_custom_command(TARGET main POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                   ${CMAKE_CURRENT_SOURCE_DIR}/fonts/JetBrainsMono-Regular.ttf
                   ${CMAKE_CURRENT_BINARY_DIR}/JetBrainsMono-Regular.ttf)

