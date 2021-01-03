#include "src/space_invaders_3d/cameras/first_person_camera.hpp"

#include <cmath>

#include <math/utils.hpp>

first_person_camera::first_person_camera()
	: m_pos { 0.0f, 0.0f,  3.0f }
	, m_front { 0.0f, 0.0f, -1.0f }
	, m_up { 0.0f, 1.0f,  0.0f }
	, m_yaw { -90.0f }
	, m_pitch { 0.0f }
{
	m_camera.projection = graphics::create_perspective();

	update_camera();
}

void first_person_camera::on_keydown(const keys& key)
{
	if (key == keys::w)
		m_pos += CAMERA_SPEED * m_front;
	if (key == keys::s)
		m_pos -= CAMERA_SPEED * m_front;
	if (key == keys::a)
		m_pos += CAMERA_SPEED * math::vector<float, 3>::cross(m_front, m_up).normalize();
	if (key == keys::d)
		m_pos -= CAMERA_SPEED * math::vector<float, 3>::cross(m_front, m_up).normalize();

	update_camera();
}

void first_person_camera::on_mouse_move(int mouse_x, int mouse_y)
{
	m_yaw -= mouse_x * CAMERA_SENSITIVITY;
	m_pitch += mouse_y * CAMERA_SENSITIVITY;

	if (m_pitch > 89.0f)
		m_pitch = 89.0f;
	if (m_pitch < -89.0f)
		m_pitch = -89.0f;

	math::vector<float, 3> direction;
	direction[0] = std::cos(math::radians(m_yaw)) * std::cos(math::radians(m_pitch));
	direction[1] = std::sin(math::radians(m_pitch));
	direction[2] = std::sin(math::radians(m_yaw)) * std::cos(math::radians(m_pitch));

	m_front = direction.normalize();

	update_camera();
}

const graphics::camera& first_person_camera::camera()
{
	return m_camera;
}

void first_person_camera::update_camera()
{
	m_camera.eye = m_pos;
	m_camera.center = m_pos + m_front;
	m_camera.up = m_up;
}