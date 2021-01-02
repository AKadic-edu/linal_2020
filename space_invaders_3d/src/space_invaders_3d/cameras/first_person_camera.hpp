#ifndef SPACE_INVADERS_3D_GAME_OBJECTS_CAMERAS_HPP
#define SPACE_INVADERS_3D_GAME_OBJECTS_CAMERAS_HPP

#include "src/space_invaders_3d/game_objects/game_object.hpp"

#include <graphics/camera.hpp>
#include <math/vector.hpp>

#include "src/space_invaders_3d/shared/keys.hpp"

class first_person_camera {
public:
	first_person_camera();

	void on_keydown(const keys& key);
	void on_mouse_move(int mouse_x, int mouse_y);

	const graphics::camera& camera();
private:
	static constexpr float CAMERA_SPEED = 0.5f;

	graphics::camera m_camera;

	math::vector<float, 3> m_pos;
	math::vector<float, 3> m_front;
	math::vector<float, 3> m_up;

	void update_camera();
};

#endif // !SPACE_INVADERS_3D_GAME_OBJECTS_CAMERAS_HPP