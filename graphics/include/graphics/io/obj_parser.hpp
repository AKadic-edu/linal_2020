#pragma once

#ifndef LINAL_GRAPHICS_IO_OBJ_PARSER_HPP
#define LINAL_GRAPHICS_IO_OBJ_PARSER_HPP

#include <string>
#include <vector>

#include <math/vector.hpp>

namespace graphics {
	class obj_parser {
	public:
		std::vector<math::vector<float, 3>> parse(const std::string& path) const;
	};
}

#endif // !LINAL_GRAPHICS_IO_OBJ_PARSER_HPP