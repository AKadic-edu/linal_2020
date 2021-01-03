#include "include/graphics/transform.hpp"

graphics::transform::transform()
	: m_rotation_matrix { math::matrix<float, 4, 4>::identity() }
	, m_scaling_matrix { math::matrix<float, 4, 4>::identity() }
	, m_translation_matrix { math::matrix<float, 4, 4>::identity() }
{ }

void graphics::transform::scale(const math::vector<float, 3>& v)
{
	m_scaling_matrix[0][0] = v[0];
	m_scaling_matrix[1][1] = v[1];
	m_scaling_matrix[2][2] = v[2];
}

void graphics::transform::translate(const math::vector<float, 3>& v)
{
	m_translation_matrix[0][3] = v[0];
	m_translation_matrix[1][3] = v[1];
	m_translation_matrix[2][3] = v[2];
}

math::matrix<float, 4, 4> graphics::transform::matrix() const
{
	return m_translation_matrix * m_rotation_matrix * m_scaling_matrix;
}