cmake_minimum_required(VERSION 3.00)
project(simple_c_debugging VERSION 1.1)
add_subdirectory(simdb)
add_executable(demo demo.c)
target_link_libraries(demo PUBLIC simdb)
target_include_directories(
	demo 
	PUBLIC 
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_BINARY_DIR}/simdb"
	"${PROJECT_SOURCE_DIR}/simdb"
)
