#ifndef SPACE_INVADERS_3D_MODELS_TRIANGLE_HPP
#define SPACE_INVADERS_3D_MODELS_TRIANGLE_HPP

#include <graphics/model.hpp>

#include <array>
#include <vector>

#include <math/matrix.hpp>

namespace graphics {
    class renderer;
}

class triangle : public graphics::model {
public:
    triangle();

    void draw(graphics::renderer& r, const math::matrix<float, 4, 4>& mvp);
private:
    std::array<math::vector<float, 3>, 3> m_v;
};

#endif // !SPACE_INVADERS_3D_MODELS_TRIANGLE_HPP