#include "src/space_invaders_3d/game_objects/target.hpp"

target::target()
	: m_current_size { 1.0f }
	, m_current_state { states::expand }
{ }

void target::on_update(float dt)
{
	if (m_current_size > MAX_SIZE)
		m_current_state = states::contract;
	else if (m_current_size < MIN_SIZE)
		m_current_state = states::expand;

	if (m_current_state == states::contract)
		m_current_size -= SIZE_INCREMENT * dt;
	else if (m_current_state == states::expand)
		m_current_size += SIZE_INCREMENT * dt;

	m_transform.scale({ m_current_size, m_current_size, m_current_size });
}

const graphics::transform& target::transform() const
{
	return m_transform;
}