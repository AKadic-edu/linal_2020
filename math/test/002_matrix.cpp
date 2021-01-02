#include <catch2/catch.hpp>

#include "include/math/matrix.hpp"

TEST_CASE("multiply", "[matrix]") {
	SECTION("1x2 * 2x2") {
		math::vector<float, 2> input1 { 1.0f, 2.0f };

		math::matrix<float, 2, 2> input2 { math::vector<float, 2>
			{ 3.0f, 5.0f },
			{ 4.0f, 6.0f },
		};

		math::vector<float, 2> expected { 11.0f, 17.0f };

		auto result = input1 * input2;

		REQUIRE(result == expected);
	}

	SECTION("2x2 * 1x2") {
		math::matrix<float, 2, 2> input1 { math::vector<float, 2>
			{ 1.0f, 2.0f },
			{ 3.0f, 4.0f },
		};
		math::vector<float, 2> input2 { 2.0f, 3.0f };

		math::vector<float, 2> expected {  8.0f, 18.0f };

		auto result = input1 * input2;

		REQUIRE(result == expected);
	}

	SECTION("2x2 * 2x2") {
		math::matrix<float, 2, 2> input1 { math::vector<float, 2>
			{ 1.0f, 2.0f },
			{ 3.0f, 4.0f },
		};
		math::matrix<float, 2, 2> input2 { math::vector<float, 2>
			{ 1.0f, 2.0f },
			{ 3.0f, 4.0f },
		};

		math::matrix<float, 2, 2> expected { math::vector<float, 2>
			{  7.0f, 10.0f },
			{ 15.0f, 22.0f },
		};

		auto result = input1 * input2;

		REQUIRE(result == expected);
	}

	SECTION("3x3 * 3x3") {
		math::matrix<float, 3, 3> input1 { math::vector<float, 3>
			{ 5.0f, 6.0f, 8.0f },
			{ 78.0f, 7.0f, 97.0f },
			{ 78.0f, 55.0f, 123.0f },
		};
		math::matrix<float, 3, 3> input2 { math::vector<float, 3>
			{ 64.0f, 55.0f, 85.0f },
			{ 436.0f, 55.0f, 9.0f },
			{ 46.0f, 4.0f, 7.0f },
		};

		math::matrix<float, 3, 3> expected { math::vector<float, 3>
			{ 3304.0f, 637.0f, 535.0f },
			{ 12506.0f, 5063.0f, 7372.0f },
			{ 34630.0f, 7807.0f, 7986.0f },
		};

		auto result = input1 * input2;

		REQUIRE(result == expected);
	}

	SECTION("3x3 * 3x3 * 3x3") {
		math::matrix<float, 3, 3> input1 { math::vector<float, 3>
			{ 1.0f, 0.0f, 0.0f },
			{ 0.0f, 1.0f, 0.0f },
			{ 0.0f, 0.0f, 1.0f },
		};
		math::matrix<float, 3, 3> input2 { math::vector<float, 3>
			{ 2.0f, 0.0f, 5.0f },
			{ 0.0f, 1.0f, 2.0f },
			{ 2.0f, 2.0f, 3.0f },
		};
		math::matrix<float, 3, 3> input3 { math::vector<float, 3>
			{ 1.0f, 0.0f, 0.0f },
			{ 2.0f, 1.0f, 1.0f },
			{ 2.0f, 2.0f, 2.0f },
		};

		math::matrix<float, 3, 3> expected { math::vector<float, 3>
			{ 2.0f, 0.0f,  5.0f },
			{ 6.0f, 3.0f, 15.0f },
			{ 8.0f, 6.0f, 20.0f },
		};

		auto result = input3 * input2 * input1;

		REQUIRE(result == expected);
	}
}

TEST_CASE(".transpose()", "[matrix]") {
	SECTION("2x2") {
		math::matrix<float, 2, 2> input { math::vector<float, 2>
			{ 1.0f, 2.0f },
			{ 3.0f, 4.0f },
		};

		math::matrix<float, 2, 2> expected { math::vector<float, 2>
			{ 1.0f, 3.0f },
			{ 2.0f, 4.0f },
		};

		auto result = input.transpose();

		REQUIRE(result == expected);
	}

	SECTION("3x3") {
		math::matrix<float, 3, 3> input{ math::vector<float, 3>
			{ 1.0f, 2.0f, 3.0f },
			{ 4.0f, 5.0f, 6.0f },
			{ 7.0f, 8.0f, 9.0f },
		};

		math::matrix<float, 3, 3> expected { math::vector<float, 3>
			{ 1.0f, 4.0f, 7.0f },
			{ 2.0f, 5.0f, 8.0f },
			{ 3.0f, 6.0f, 9.0f },
		};

		auto result = input.transpose();

		REQUIRE(result == expected);
	}

	SECTION("2x3") {
		math::matrix<float, 2, 3> input { math::vector<float, 3>
			{ 1.0f, 2.0f, 3.0f },
			{ 4.0f, 5.0f, 6.0f },
		};

		math::matrix<float, 3, 2> expected { math::vector<float, 2>
			{ 1.0f, 4.0f },
			{ 2.0f, 5.0f },
			{ 3.0f, 6.0f },
		};

		auto result = input.transpose();

		REQUIRE(result == expected);
	}

	SECTION("3x2") {
		math::matrix<float, 3, 2> input { math::vector<float, 2>
			{ 1.0f, 4.0f },
			{ 2.0f, 5.0f },
			{ 3.0f, 6.0f },
		};

		math::matrix<float, 2, 3> expected { math::vector<float, 3>
			{ 1.0f, 2.0f, 3.0f },
			{ 4.0f, 5.0f, 6.0f },
		};

		auto result = input.transpose();

		REQUIRE(result == expected);
	}
}