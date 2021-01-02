#pragma once

#ifndef LINAL_GRAPHICS_SDL2_SDL2_RENDERER_HPP
#define LINAL_GRAPHICS_SDL2_SDL2_RENDERER_HPP

#include "include/graphics/renderer.hpp"

#include <SDL2/SDL.h>

namespace graphics {
	class sdl2_renderer : public renderer {
	public:
		void init() override;
		void destroy() override;

		void draw(scene& s) override;

		void draw_model(
			const std::vector<math::vector<float, 3>>& vertices,
			const math::matrix<float, 4, 4>& mvp) override;

		void draw_triangle(
			const math::vector<float, 3> vertices[3],
			const math::matrix<float, 4, 4>& mvp) override;
	private:
		SDL_Renderer* m_renderer;
		SDL_Window* m_window;
	};
}

#endif // !LINAL_GRAPHICS_SDL2_SDL2_RENDERER_HPP
