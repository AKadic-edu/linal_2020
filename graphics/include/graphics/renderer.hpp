#pragma once

#ifndef LINAL_GRAPHICS_RENDERER_HPP
#define LINAL_GRAPHICS_RENDERER_HPP

#include <memory>
#include <vector>

#include <math/matrix.hpp>
#include <math/vector.hpp>

namespace graphics {
	struct scene;

	class renderer {
	public:
		virtual void init() = 0;
		virtual void destroy() = 0;

		virtual void draw(scene& s) = 0;

		virtual void draw_model(
			const std::vector<math::vector<float, 3>>& vertices,
			const math::matrix<float, 4, 4>& mvp) = 0;

		virtual void draw_triangle(
			const math::vector<float, 3> vertices[3],
			const math::matrix<float, 4, 4>& mvp) = 0;
	};

	std::unique_ptr<renderer> create_renderer();
}

#endif // !LINAL_GRAPHICS_RENDERER_HPP