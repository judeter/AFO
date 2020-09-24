
project(TestFunctions)

add_library(TestFunctions TestFunctions.h TestFunctions.cpp)

# If a project links to the library "Optimizer" then it must also include the Optimizer directory for header files.
target_include_directories(TestFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Create folders to mirror source directory structure.
set_target_properties(TestFunctions PROPERTIES FOLDER "TestFunctions")