#ifndef SPACE_INVADERS_3D_MODELS_CUBE_HPP
#define SPACE_INVADERS_3D_MODELS_CUBE_HPP

#include <graphics/model.hpp>

#include <vector>

#include <math/matrix.hpp>

namespace graphics {
    class renderer;
}

class cube : public graphics::model {
public:
    cube();

    void draw(graphics::renderer& r, const math::matrix<float, 4, 4>& mvp);
private:
    std::vector<math::vector<float, 3>> m_v;
};

#endif // !SPACE_INVADERS_3D_MODELS_CUBE_HPP