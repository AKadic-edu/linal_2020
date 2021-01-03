#include "src/space_invaders_3d/game_objects/space_ship.hpp"

#include "src/space_invaders_3d/game_objects/bullet.hpp"

space_ship::space_ship(
	graphics::scene& scene,
	std::vector<std::unique_ptr<game_object>>& game_objects
)
	: m_scene { scene }
	, m_game_objects { game_objects }
	, m_forward { -1.0f, 0.0f, 0.0f }
	, m_velocity { 0.0f }
{ }

void space_ship::on_update(float dt)
{
	move_forwards(dt);
	decrease_velocity();
}

void space_ship::on_fire_bullet()
{
	auto b = std::make_unique<bullet>(m_transform);

	m_scene.transforms.push_back(b->transform());
	m_scene.instances.push_back({ 1, (int)m_scene.transforms.size() - 1 });

	m_game_objects.push_back(std::move(b));
}

void space_ship::on_gas_pressed()
{
	increase_velocity();
}

const graphics::transform& space_ship::transform() const
{
	return m_transform;
}

void space_ship::increase_velocity()
{
	m_velocity += MAX_VELOCITY / (m_velocity + VELOCITY_INCREMENT);

	if (m_velocity > MAX_VELOCITY)
		m_velocity = MAX_VELOCITY;
}

void space_ship::decrease_velocity()
{
	if (m_velocity == 0.0f)
		return;

	m_velocity -= MAX_VELOCITY / (m_velocity + VELOCITY_INCREMENT);

	if (m_velocity < 0.0f)
		m_velocity = 0.0f;
}

void space_ship::move_forwards(float dt)
{
	const math::vector<float, 3> translation { m_velocity, 0.0f, 0.0f };

	m_transform.translate(m_transform.translation() + (dt * translation));
}
