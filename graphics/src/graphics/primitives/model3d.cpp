#include "include/graphics/primitives/model3d.hpp"

#include "include/graphics/renderer.hpp"

graphics::model3d::model3d(const std::vector<math::vector<float, 3>>& vertices)
	: m_vertices { vertices }
{ }

void graphics::model3d::draw(renderer& r, const math::matrix<float, 4, 4>& mvp)
{
	r.draw_model(m_vertices, mvp);
}