
project(UnitTest)

add_executable(Test_Optimizer Test_Optimizer.cpp)
add_executable(Test_TestFunctions Test_TestFunctions.cpp)

target_link_libraries(Test_Optimizer PUBLIC Optimizer)
target_link_libraries(Test_TestFunctions PUBLIC TestFunctions)

# Create folders to mirror source directory structure.
set_target_properties(Test_Optimizer PROPERTIES FOLDER "UnitTest")
set_target_properties(Test_TestFunctions PROPERTIES FOLDER "UnitTest")
