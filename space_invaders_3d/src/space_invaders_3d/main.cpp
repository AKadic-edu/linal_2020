#include <map>

#include <SDL2/SDL.h>

#include <graphics/renderer.hpp>
#include <graphics/scene.hpp>
#include <graphics/io/model_loader.hpp>

#include "src/space_invaders_3d/cameras/first_person_camera.hpp"
#include "src/space_invaders_3d/game_objects/target.hpp"
#include "src/space_invaders_3d/models/cube.hpp"
#include "src/space_invaders_3d/shared/keys.hpp"

std::map<const SDL_Keycode, keys> key_map {
    { SDLK_a, keys::a },
    { SDLK_d, keys::d },
    { SDLK_s, keys::s },
    { SDLK_w, keys::w },
};

first_person_camera camera;
target t1, t2, t3;

void processInput(const SDL_KeyboardEvent& e)
{
    camera.on_keydown(key_map[e.keysym.sym]);
}

void processInput(const SDL_MouseMotionEvent& e)
{
    camera.on_mouse_move(e.xrel, e.yrel);
}

int main(int argc, char* argv[])
{
    graphics::model_loader ml;

    graphics::scene s;

    // init models
    s.models.push_back(std::make_unique<cube>());
    s.models.push_back(ml.load("assets/models/sphere.obj"));

    // init camera
    s.cameras.push_back(camera.camera());
    s.primary_camera = 0;

    // target1
    auto& t1_transform = t1.transform();
    s.transforms.push_back(t1_transform);
    s.instances.push_back({ 1, 0 });

    bool running = true;

    auto renderer = graphics::create_renderer();
    renderer->init();

    unsigned int last_time = 0, current_time;

    SDL_Event e;
    while (running) {
        current_time = SDL_GetTicks();
        float dt = current_time - last_time;
        last_time = current_time;

        while (SDL_PollEvent(&e)) {
            switch (e.type)
            {
            case SDL_KEYDOWN:
                processInput(e.key);
                break;
            case SDL_MOUSEMOTION:
                processInput(e.motion);
                break;
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
            }
        }

        t1.on_update(dt);

        renderer->draw(s);
    }

    renderer->destroy();

    SDL_Quit();

	return 0;
}