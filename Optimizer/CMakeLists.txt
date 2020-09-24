
project(Optimizer)

add_library(Optimizer Optimizer.h Optimizer.cpp Dummy.cpp)

# If a project links to the library "Optimizer" then it must also include the Optimizer directory for header files.
target_include_directories(Optimizer INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Create folders to mirror source directory structure.
set_target_properties(Optimizer PROPERTIES FOLDER "Optimizer")
