
project(UnitTest)

add_executable(Test_Optimizer Test_Optimizer.cpp)
add_executable(Test_TestFunctions Test_TestFunctions.cpp)

target_link_libraries(Test_Optimizer PUBLIC Optimizer)
target_link_libraries(Test_TestFunctions PUBLIC TestFunctions)


#target_include_directories(Test_Optimizer PRIVATE ${BOOST_INCLUDE_DIRS})
#target_include_directories(Test_TestFunctions PRIVATE ${BOOST_INCLUDE_DIRS})

# Create folders to mirror source directory structure.
set_target_properties(Test_Optimizer PROPERTIES FOLDER "UnitTest")
set_target_properties(Test_TestFunctions PROPERTIES FOLDER "UnitTest")
