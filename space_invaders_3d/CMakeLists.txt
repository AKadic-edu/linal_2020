add_executable(space_invaders_3d
	"src/space_invaders_3d/main.cpp"
	"src/space_invaders_3d/cameras/first_person_camera.cpp"
	"src/space_invaders_3d/game_objects/target.cpp"
	"src/space_invaders_3d/models/cube.cpp" 
	"src/space_invaders_3d/models/triangle.cpp")

target_include_directories(space_invaders_3d PRIVATE ".")

add_custom_command(TARGET space_invaders_3d POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   "${CMAKE_CURRENT_LIST_DIR}/assets" "$<TARGET_FILE_DIR:space_invaders_3d>/assets")

target_link_libraries(space_invaders_3d PRIVATE graphics)

find_package(SDL2 REQUIRED)
target_link_libraries(space_invaders_3d PRIVATE SDL2::SDL2 SDL2::SDL2main)