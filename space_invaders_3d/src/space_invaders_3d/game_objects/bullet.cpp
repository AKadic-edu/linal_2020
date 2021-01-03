#include "src/space_invaders_3d/game_objects/bullet.hpp"

bullet::bullet(
	const graphics::transform& parent_transform
)
	: m_transform { parent_transform }
{
	m_transform.scale({ 0.1f, 0.1f, 0.1f });
}

void bullet::on_update(float dt)
{

}

const graphics::transform& bullet::transform() const
{
	return m_transform;
}