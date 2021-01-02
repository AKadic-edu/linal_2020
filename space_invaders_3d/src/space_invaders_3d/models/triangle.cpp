#include "src/space_invaders_3d/models/triangle.hpp"

#include <graphics/renderer.hpp>

triangle::triangle()
    : m_v { std::array<math::vector<float, 3>, 3> { math::vector<float, 3>
        { -0.5f, -0.5f, 0.0f },
        {  0.0f,  0.5f, 0.0f },
        {  0.5f, -0.5f, 0.0f } } }
{ }

void triangle::draw(graphics::renderer& r, const math::matrix<float, 4, 4>& mvp)
{
    r.draw_triangle(m_v.data(), mvp);
}