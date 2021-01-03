#pragma once

#ifndef LINAL_GRAPHICS_IO_MODEL_LOADER_HPP
#define LINAL_GRAPHICS_IO_MODEL_LOADER_HPP

#include <memory>
#include <string>
#include <vector>

#include <math/vector.hpp>

#include "obj_parser.hpp"

namespace graphics {
	class model;

	class model_loader {
	public:
		std::unique_ptr<model> load(const std::string& path) const;
	private:
		obj_parser m_obj_parser;
	};
}

#endif // !LINAL_GRAPHICS_IO_MODEL_LOADER_HPP