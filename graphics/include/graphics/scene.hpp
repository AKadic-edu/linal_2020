#pragma once

#ifndef LINAL_GRAPHICS_SCENE_HPP
#define LINAL_GRAPHICS_SCENE_HPP

#include <memory>
#include <vector>

#include "camera.hpp"
#include "instance.hpp"
#include "model.hpp"
#include "transform.hpp"

namespace graphics {
	struct scene {
		int primary_camera;
		std::vector<std::reference_wrapper<const camera>> cameras;

		std::vector<instance> instances;
		std::vector<std::unique_ptr<model>> models;
		std::vector<std::reference_wrapper<const transform>> transforms;
	};
}

#endif // !LINAL_GRAPHICS_SCENE_HPP