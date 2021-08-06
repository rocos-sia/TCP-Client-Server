cmake_minimum_required(VERSION 3.10)

project(C++)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)


find_package(Boost REQUIRED COMPONENTS system)

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/src   SrcFiles)

add_executable(write  src/write.cpp)
target_link_libraries(write ${Boost_LIBRARIES})
target_link_libraries(write pthread)
target_link_libraries(write rt)

add_executable(read  src/read.cpp)
target_link_libraries(read ${Boost_LIBRARIES})
target_link_libraries(read pthread)
target_link_libraries(read rt)


add_executable(share_memory  src/share_memory.cpp)
target_link_libraries(share_memory ${Boost_LIBRARIES})
target_link_libraries(share_memory pthread)
target_link_libraries(share_memory rt)


add_executable(atomic  src/atomic.cpp)
target_link_libraries(atomic ${Boost_LIBRARIES})
target_link_libraries(atomic pthread)
target_link_libraries(atomic rt)

add_executable(test__  src/test__.cpp)
target_link_libraries(test__ ${Boost_LIBRARIES})
target_link_libraries(test__ pthread)
target_link_libraries(test__ rt)
