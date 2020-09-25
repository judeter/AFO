cmake_minimum_required(VERSION 3.10...3.18)

project(afo VERSION 0.1)

set(BOOST_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/boost)

add_subdirectory(Optimizer)
add_subdirectory(TestFunctions)
add_subdirectory(UnitTest)

# This allow the creating of VS folders created by sub-projects.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)