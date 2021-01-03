#pragma once

#ifndef SPACE_INVADERS_3D_GAME_OBJECTS_SPACE_SHIP_HPP
#define SPACE_INVADERS_3D_GAME_OBJECTS_SPACE_SHIP_HPP

#include "src/space_invaders_3d/game_objects/game_object.hpp"

#include <graphics/scene.hpp>
#include <graphics/transform.hpp>

class space_ship : public game_object {
public:
	space_ship(
		graphics::scene& scene, 
		std::vector<std::unique_ptr<game_object>>& game_objects);

	void on_update(float dt) override;

	void on_fire_bullet();
	void on_gas_pressed();

	const graphics::transform& transform() const;
private:
	float MAX_VELOCITY = 0.1f;
	float VELOCITY_INCREMENT = 0.01f;

	graphics::scene& m_scene;
	std::vector<std::unique_ptr<game_object>>& m_game_objects;

	graphics::transform m_transform;

	math::vector<float, 3> m_forward;

	float m_velocity;

	void increase_velocity();
	void decrease_velocity();

	void move_forwards(float dt);
};

#endif // !SPACE_INVADERS_3D_GAME_OBJECTS_SPACE_SHIP_HPP