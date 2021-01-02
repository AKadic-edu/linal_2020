#include <catch2/catch.hpp>

#include "include/math/vector.hpp"

TEST_CASE("operator*", "[vector]") {
	SECTION("scalar") {
		math::vector<int, 3> input { 1, 2, 3 };
		int scalar = 3;

		math::vector<int, 3> expected { 3, 6, 9 };

		auto result = scalar * input;

		REQUIRE(result == expected);
	}
}

TEST_CASE("operator+=", "[vector]") {
	SECTION("vector") {
		math::vector<int, 3> input1 { 1, 1, 3 };
		math::vector<int, 3> input2 { 2, 2, 3 };

		math::vector<int, 3> expected { 3, 3, 6 };

		auto result = input1 += input2;

		REQUIRE(result == expected);
	}
}