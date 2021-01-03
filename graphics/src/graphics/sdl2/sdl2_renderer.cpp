#include "src/graphics/sdl2/sdl2_renderer.hpp"

#include <math/matrix.hpp>
#include <math/vector.hpp>

#include "include/graphics/model.hpp"
#include "include/graphics/scene.hpp"

std::unique_ptr<graphics::renderer> graphics::create_renderer()
{
    return std::make_unique<sdl2_renderer>();
}

void graphics::sdl2_renderer::init()
{
    SDL_InitSubSystem(SDL_INIT_VIDEO);

    m_window = SDL_CreateWindow(
        "Jeu de la vie",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_SHOWN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

void graphics::sdl2_renderer::destroy()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);

    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void graphics::sdl2_renderer::draw(scene& s)
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    math::matrix<float, 4, 4> view = s.cameras[s.primary_camera].get().view();
    math::matrix<float, 4, 4> projection = s.cameras[s.primary_camera].get().projection;

    for (auto i : s.instances) {
        math::matrix<float, 4, 4> model = s.transforms[i.transform_id].get().matrix();
        math::matrix<float, 4, 4> mvp = projection * view * model;

        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        s.models[i.model_id]->draw(*this, mvp);
    }

    SDL_RenderPresent(m_renderer);
}

void graphics::sdl2_renderer::draw_model(
    const std::vector<math::vector<float, 3>>& vertices,
    const math::matrix<float, 4, 4>& mvp)
{
    for (int i = 0; i < vertices.size(); i+=3) {
        math::vector<float, 3> v[3];
        v[0] = vertices[i];
        v[1] = vertices[i + 1];
        v[2] = vertices[i + 2];
        draw_triangle(v, mvp);
    }
}

void graphics::sdl2_renderer::draw_triangle(
	const math::vector<float, 3> vertices[3],
	const math::matrix<float, 4, 4>& mvp)
{
    math::vector<float, 2> screen_vertices[3];

    for (int i = 0; i < 3; ++i) {
        math::vector<float, 4> h_vertex { 
            vertices[i][0],
            vertices[i][1],
            vertices[i][2],
            1.0f 
        };

        auto v = h_vertex * mvp;
        auto w = v[3];

        float width = 640.0f, height = 480.0f;

        float z = (v[2] != 0) ? v[2] : 1.0f;
        float x = v[0] / z, y = v[1] / z;

        if (x < -1.0f || x > 1.0f ||
            y < -1.0f || y > 1.0f)
            return;

        float screen_x = (width / 2.0f) + (x / w) * (width / w);
        float screen_y = height - ((height / 2.0f) + (y / w) * (height / w));

        screen_vertices[i] = { screen_x, screen_y };
    }

    SDL_RenderDrawLineF(m_renderer,
        screen_vertices[0][0], screen_vertices[0][1],
        screen_vertices[1][0], screen_vertices[1][1]);
    SDL_RenderDrawLineF(m_renderer,
        screen_vertices[1][0], screen_vertices[1][1],
        screen_vertices[2][0], screen_vertices[2][1]);
    SDL_RenderDrawLineF(m_renderer,
        screen_vertices[2][0], screen_vertices[2][1],
        screen_vertices[0][0], screen_vertices[0][1]);
}