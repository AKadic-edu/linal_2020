add_library(math INTERFACE)

target_include_directories(math INTERFACE "${CMAKE_CURRENT_LIST_DIR}/include")

add_executable(math_tests
	"test/000_catch_main.cpp"
	"test/001_vector.cpp"
	"test/002_matrix.cpp")
	
target_include_directories(math_tests PRIVATE "${CMAKE_CURRENT_LIST_DIR}")

find_package(Catch2 CONFIG REQUIRED)
target_link_libraries(math_tests PRIVATE Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(math_tests)