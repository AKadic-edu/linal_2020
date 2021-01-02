#pragma once

#ifndef LINAL_MATH_MATRIX_HPP
#define LINAL_MATH_MATRIX_HPP

#include "vector.hpp"

#include <cassert>

namespace math {
	template<typename T, size_t M, size_t N>
	struct matrix {
		vector<T, N> m[M] { 0 };

		static matrix<T, M, N> identity()
		{
			assert(M == N);

			matrix<T, M, N> out;

			for (int i = 0; i < M; ++i) {
				out[i][i] = (T)1;
			}

			return out;
		}

		vector<T, N> operator*(const vector<T, N>& other) const
		{
			vector<T, N> out;

			for (int i = 0; i < M; ++i) {
				out[i] += m[i] * other;
			}

			return out;
		}

		matrix<T, M, N> operator*(const matrix<T, M, N>& other) const
		{
			matrix<T, M, N> out;

			auto a = m;
			auto b = other.transpose();

			for (int i = 0; i < M; ++i) {
				for (int j = 0; j < N; ++j) {
					out[j][i] = vector<T, N>::dot(a[i], b[j]);
				}
			}

			return out;
		}

		bool operator==(const matrix<T, M, N>& other) const
		{
			for (int i = 0; i < M; ++i) {
				if (m[i] != other[i]) {
					return false;
				}
			}

			return true;
		}

		const vector<T, N>& operator[](int index) const
		{
			return m[index];
		}

		vector<T, N>& operator[](int index)
		{
			return m[index];
		}

		matrix<T, N, M> transpose() const
		{
			matrix<float, N, M> out;

			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					out[i][j] = m[j][i];
				}
			}

			return out;
		}
	};

	template<typename T, size_t M, size_t N>
	vector<T, N> operator*(const vector<T, N>& a, const matrix<T, M, N>& b)
	{
		vector<T, N> out;

		auto b_transposed = b.transpose();

		for (size_t i = 0; i < M; ++i) {
			out[i] += a * b_transposed[i];
		}

		return out;
	}
}

#endif // !LINAL_MATH_MATRIX_HPP