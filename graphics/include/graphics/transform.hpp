#pragma once

#ifndef LINAL_GRAPHICS_TRANSFORM_HPP
#define LINAL_GRAPHICS_TRANSFORM_HPP

#include <math/matrix.hpp>

namespace graphics {
	class transform {
	public:
		transform();

		const math::vector<float, 3> scale() const;
		const math::vector<float, 3> translation() const;

		void scale(const math::vector<float, 3>& v);
		void translate(const math::vector<float, 3>& v);

		math::matrix<float, 4, 4> matrix() const;
	private:
		math::matrix<float, 4, 4> m_rotation_matrix;
		math::matrix<float, 4, 4> m_scaling_matrix;
		math::matrix<float, 4, 4> m_translation_matrix;
	};
}

#endif // !LINAL_GRAPHICS_TRANSFORM_HPP