#pragma once

#ifndef SPACE_INVADERS_3D_GAME_OBJECTS_BULLET_HPP
#define SPACE_INVADERS_3D_GAME_OBJECTS_BULLET_HPP

#include "src/space_invaders_3d/game_objects/game_object.hpp"

#include <graphics/transform.hpp>

class bullet : public game_object {
public:
	bullet(const graphics::transform& parent_transform);

	void on_update(float dt) override;

	const graphics::transform& transform() const;
private:
	graphics::transform m_transform;
};

#endif // !SPACE_INVADERS_3D_GAME_OBJECTS_BULLET_HPP