#pragma once

#ifndef LINAL_GRAPHICS_CAMERA_HPP
#define LINAL_GRAPHICS_CAMERA_HPP

#include <math/matrix.hpp>
#include <math/vector.hpp>

namespace graphics {
	struct camera {
		math::vector<float, 3> eye, center, up;
		math::matrix<float, 4, 4> projection;

		math::matrix<float, 4, 4> view() const;
	};

	math::matrix<float, 4, 4> create_ortho();
	math::matrix<float, 4, 4> create_perspective();
}

#endif // !LINAL_GRAPHICS_CAMERA_HPP