#pragma once

#ifndef LINAL_GRAPHICS_MODEL_HPP
#define LINAL_GRAPHICS_MODEL_HPP

#include <math/matrix.hpp>

namespace graphics {
	class renderer;

	class model {
	public:
		virtual void draw(renderer& r, const math::matrix<float, 4, 4>& t) = 0;
	};
}

#endif // !LINAL_GRAPHICS_MODEL_HPP