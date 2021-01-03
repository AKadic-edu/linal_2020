#include "include/graphics/camera.hpp"

#include <cmath>

#include <math/utils.hpp>

#include <glm/gtc/matrix_transform.hpp>

math::matrix<float, 4, 4> graphics::camera::view() const
{
	math::vector<float, 3> camDir = (eye - center).normalize();
	math::vector<float, 3> camRight = math::vector<float, 3>::cross(up, camDir).normalize();
	math::vector<float, 3> camUp = math::vector<float, 3>::cross(camDir, camRight);

	auto a = math::matrix<float, 4, 4>::identity();
	a[0][3] = -eye[0];
	a[1][3] = -eye[1];
	a[2][3] = -eye[2];

	auto b = math::matrix<float, 4, 4>::identity();
	b[0][0] = camRight[0];
	b[0][1] = camRight[1];
	b[0][2] = camRight[2];
	b[1][0] = camUp[0];
	b[1][1] = camUp[1];
	b[1][2] = camUp[2];
	b[2][0] = camDir[0];
	b[2][1] = camDir[1];
	b[2][2] = camDir[2];

	return b * a;
}

math::matrix<float, 4, 4> graphics::create_ortho()
{
    float l = -1, r = 1;
    float b = -1, t = 1;
    float n = 0.1f, f = 100.0f;

    math::matrix<float, 4, 4> projection = math::matrix<float, 4, 4>::identity();
    projection[0][0] = 2.0f / (r - l);
    projection[1][1] = 2.0f / (t - b);
    projection[2][2] = -2.0f / (f - n);
    projection[3][0] = -(r + l) / (r - l);
    projection[3][1] = -(t + b) / (t - b);
    projection[3][2] = -(f + n) / (f - n);

    return projection;
}

math::matrix<float, 4, 4> graphics::create_perspective()
{
    float fov = 90.0f;
    float far = 100.0f, near = 0.1f;
    float scale = 1 / std::tan(math::radians(fov / 2.0f));

    math::matrix<float, 4, 4> projection = math::matrix<float, 4, 4>::identity();
    projection[0][0] = scale;
    projection[1][1] = scale;
    projection[2][2] = -far / (far - near);
    projection[3][2] = -1.0f;
    projection[2][3] = (-far * near) / (far - near);

    return projection;

 //   auto mat = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);
	//math::matrix<float, 4, 4> out = math::matrix<float, 4, 4>::identity();
	//out[0][0] = mat[0][0];
	//out[0][1] = mat[1][0];
	//out[0][2] = mat[2][0];
	//out[0][3] = mat[3][0];

	//out[1][0] = mat[0][1];
	//out[1][1] = mat[1][1];
	//out[1][2] = mat[2][1];
	//out[1][3] = mat[3][1];

	//out[2][0] = mat[0][2];
	//out[2][1] = mat[1][2];
	//out[2][2] = mat[2][2];
	//out[2][3] = mat[3][2];

	//out[3][0] = mat[0][3];
	//out[3][1] = mat[1][3];
	//out[3][2] = mat[2][3];
	//out[3][3] = mat[3][3];

	//return out.transpose();
}