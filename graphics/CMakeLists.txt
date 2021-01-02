add_library(graphics STATIC 
	"src/graphics/camera.cpp"
	"src/graphics/transform.cpp"
	"src/graphics/sdl2/sdl2_renderer.cpp" "include/graphics/instance.hpp")

target_include_directories(graphics
	INTERFACE "${CMAKE_CURRENT_LIST_DIR}/include"
	PRIVATE "${CMAKE_CURRENT_LIST_DIR}")

target_link_libraries(graphics 
	PUBLIC math)

find_package(SDL2 REQUIRED)
target_link_libraries(graphics PRIVATE SDL2::SDL2)