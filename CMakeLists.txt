cmake_minimum_required(VERSION 3.10)

project(InspireHand)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)


find_package(Boost REQUIRED COMPONENTS system)

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/src   SrcFiles)

add_executable(test1 src/test1.cpp)
#target_link_libraries(test1 Boost::system)
target_link_libraries(test1 ${Boost_LIBRARIES})

add_executable(test2 src/test2.cpp)
#target_link_libraries(test2 Boost::system)
target_link_libraries(test2 ${Boost_LIBRARIES})
