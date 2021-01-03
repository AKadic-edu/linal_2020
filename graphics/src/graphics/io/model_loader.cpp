#include "include/graphics/io/model_loader.hpp"

#include "include/graphics/primitives/model3d.hpp"

std::unique_ptr<graphics::model> graphics::model_loader::load(const std::string& path) const
{
	auto vertices = m_obj_parser.parse(path);

	return std::make_unique<model3d>(vertices);
}