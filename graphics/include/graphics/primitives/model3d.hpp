#pragma once

#ifndef LINAL_GRAPHICS_PRIMITIVES_MODEL3D_HPP
#define LINAL_GRAPHICS_PRIMITIVES_MODEL3D_HPP

#include "../model.hpp"

#include <vector>

#include <math/vector.hpp>

namespace graphics {
	class renderer;

	class model3d : public model {
	public:
		model3d(const std::vector<math::vector<float, 3>>& vertices);

		void draw(renderer& r, const math::matrix<float, 4, 4>& mvp) override;
	private:
		std::vector<math::vector<float, 3>> m_vertices;
	};
}

#endif // !LINAL_GRAPHICS_PRIMITIVES_MODEL3D_HPP