#pragma once

#ifndef LINAL_MATH_VECTOR_HPP
#define LINAL_MATH_VECTOR_HPP

#include <cmath>

namespace math {
	template<typename T, size_t N>
	struct vector {
		T v[N] { 0 };

		static T dot(const vector<T, N>& a, const vector<T, N>& b)
		{
			T sum = 0;

			for (int i = 0; i < N; ++i) {
				sum += a[i] * b[i];
			}

			return sum;
		}

		static vector<T, 3> cross(
			const vector<T, 3>& a, 
			const vector<T, 3>& b)
		{
			vector<T, 3> out;

			out[0] = (a[1] * b[2]) - (a[2] * b[1]);
			out[1] = (a[2] * b[0]) - (a[0] * b[2]);
			out[2] = (a[0] * b[1]) - (a[1] * b[0]);

			return out;
		}

		T magnitude() const
		{
			T out = 0;

			for (int i = 0; i < N; ++i) {
				out += v[i] * v[i];
			}

			out = std::sqrt(out);

			return out;
		}

		vector<T, N> normalize() const
		{
			vector<T, N> out;

			T length = magnitude();

			for (int i = 0; i < N; ++i) {
				out[i] = v[i] / length;
			}

			return out;
		}

		vector<T, N> operator+(const vector<T, N>& other) const
		{
			vector<T, N> out;

			for (int i = 0; i < N; ++i) {
				out[i] = v[i] + other[i];
			}

			return out;
		}

		vector<T, N> operator-(const vector<T, N>& other) const
		{
			vector<T, N> out;

			for (int i = 0; i < N; ++i) {
				out[i] = v[i] - other[i];
			}

			return out;
		}

		T operator*(const vector<T, N>& other) const
		{
			T out = 0;

			for (size_t i = 0; i < N; ++i) {
				out += v[i] * other[i];
			}

			return out;
		}

		vector<T, N>& operator+=(const vector<T, N>& other)
		{
			for (int i = 0; i < N; ++i) {
				v[i] += other[i];
			}

			return *this;
		}

		vector<T, N>& operator-=(const vector<T, N>& other)
		{
			for (int i = 0; i < N; ++i) {
				v[i] -= other[i];
			}

			return *this;
		}

		bool operator==(const vector<T, N>& other) const
		{
			for (int i = 0; i < N; ++i) {
				if (v[i] != other[i]) {
					return false;
				}
			}

			return true;
		}

		bool operator!=(const vector<T, N>& other) const
		{
			for (int i = 0; i < N; ++i) {
				if (v[i] == other[i]) {
					return false;
				}
			}

			return true;
		}

		const T& operator[](int index) const
		{
			return v[index];
		}

		T& operator[](int index)
		{
			return v[index];
		}
	};

	template<typename T, size_t N>
	vector<T, N> operator*(const T scalar, const vector<T, N>& a)
	{
		vector<T, N> out;

		for (int i = 0; i < N; ++i) {
			out[i] = a[i] * scalar;
		}

		return out;
	}
}

#endif // !LINAL_MATH_VECTOR_HPP