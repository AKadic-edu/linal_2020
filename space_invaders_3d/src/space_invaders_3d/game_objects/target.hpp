#ifndef SPACE_INVADERS_3D_GAME_OBJECTS_TARGET_HPP
#define SPACE_INVADERS_3D_GAME_OBJECTS_TARGET_HPP

#include "src/space_invaders_3d/game_objects/game_object.hpp"

#include <graphics/transform.hpp>

class target : public game_object {
public:
	target();

	void on_update(float dt) override;

	const graphics::transform& transform() const;
private:
	enum class states {
		expand,
		contract,
	};

	static constexpr float MAX_SIZE = 3.0f;
	static constexpr float MIN_SIZE = 1.0f;
	static constexpr float SIZE_INCREMENT = 0.001f;

	graphics::transform m_transform;

	float m_current_size;
	states m_current_state;
};

#endif // !SPACE_INVADERS_3D_GAME_OBJECTS_TARGET_HPP