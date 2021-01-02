#include "src/space_invaders_3d/models/cube.hpp"

#include <graphics/renderer.hpp>

cube::cube()
	: m_v { std::vector<math::vector<float, 3>> { math::vector<float, 3>
            { -0.5f, -0.5f, -0.5f },
            {  0.5f, -0.5f, -0.5f },
            {  0.5f,  0.5f, -0.5f },
            {  0.5f,  0.5f, -0.5f },
            { -0.5f,  0.5f, -0.5f },
            { -0.5f, -0.5f, -0.5f },

            { -0.5f, -0.5f,  0.5f },
            {  0.5f, -0.5f,  0.5f },
            {  0.5f,  0.5f,  0.5f },
            {  0.5f,  0.5f,  0.5f },
            { -0.5f,  0.5f,  0.5f },
            { -0.5f, -0.5f,  0.5f },

            { -0.5f,  0.5f,  0.5f },
            { -0.5f,  0.5f, -0.5f },
            { -0.5f, -0.5f, -0.5f },
            { -0.5f, -0.5f, -0.5f },
            { -0.5f, -0.5f,  0.5f },
            { -0.5f,  0.5f,  0.5f },

            { 0.5f,  0.5f,  0.5f },
            { 0.5f,  0.5f, -0.5f },
            { 0.5f, -0.5f, -0.5f },
            { 0.5f, -0.5f, -0.5f },
            { 0.5f, -0.5f,  0.5f },
            { 0.5f,  0.5f,  0.5f },

            { -0.5f, -0.5f, -0.5f },
            {  0.5f, -0.5f, -0.5f },
            {  0.5f, -0.5f,  0.5f },
            {  0.5f, -0.5f,  0.5f },
            { -0.5f, -0.5f,  0.5f },
            { -0.5f, -0.5f, -0.5f },

            { -0.5f,  0.5f, -0.5f },
            {  0.5f,  0.5f, -0.5f },
            {  0.5f,  0.5f,  0.5f },
            {  0.5f,  0.5f,  0.5f },
            { -0.5f,  0.5f,  0.5f },
            { -0.5f,  0.5f, -0.5f },
        } }
{ }

void cube::draw(graphics::renderer& r, const math::matrix<float, 4, 4>& mvp)
{
    r.draw_model(m_v, mvp);
}