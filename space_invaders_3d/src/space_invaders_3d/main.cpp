#include <map>
#include <memory>

#include <SDL2/SDL.h>

#include <graphics/renderer.hpp>
#include <graphics/scene.hpp>
#include <graphics/io/model_loader.hpp>

#include "src/space_invaders_3d/cameras/first_person_camera.hpp"
#include "src/space_invaders_3d/game_objects/bullet.hpp"
#include "src/space_invaders_3d/game_objects/space_ship.hpp"
#include "src/space_invaders_3d/game_objects/target.hpp"
#include "src/space_invaders_3d/models/cube.hpp"
#include "src/space_invaders_3d/shared/keys.hpp"

std::map<const SDL_Keycode, keys> key_map {
    { SDLK_a, keys::a },
    { SDLK_d, keys::d },
    { SDLK_s, keys::s },
    { SDLK_w, keys::w },

    { SDLK_SPACE, keys::space },
    { SDLK_LSHIFT, keys::lshift },
};

graphics::scene s;

first_person_camera camera;

std::vector<std::unique_ptr<game_object>> game_objects;
space_ship ship { s, game_objects };

void processInput(const SDL_KeyboardEvent& e)
{
    const keys key = key_map[e.keysym.sym];

    camera.on_keydown(key);
    
    if (key == keys::lshift)
        ship.on_gas_pressed();
    if (key == keys::space)
        ship.on_fire_bullet();
}

void processInput(const SDL_MouseMotionEvent& e)
{
    camera.on_mouse_move(e.xrel, e.yrel);
}

int main(int argc, char* argv[])
{
    graphics::model_loader ml;

    // init models
    s.models.push_back(std::make_unique<cube>());
    s.models.push_back(ml.load("assets/models/sphere.obj"));
    s.models.push_back(ml.load("assets/models/spaceship.obj"));
    s.models.push_back(ml.load("assets/models/target.obj"));

    // init camera
    s.cameras.push_back(camera.camera());
    s.primary_camera = 0;

    // spaceship
    s.transforms.push_back(ship.transform());
    s.instances.push_back({ 2, (int)s.transforms.size() - 1 });

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

        ship.on_update(dt);

        for (auto& game_object : game_objects)
            game_object->on_update(dt);

        renderer->draw(s);
    }

    renderer->destroy();

    SDL_Quit();

	return 0;
}