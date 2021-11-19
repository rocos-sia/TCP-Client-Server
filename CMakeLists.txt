cmake_minimum_required(VERSION 3.10)

project(C++)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)


find_package(Boost REQUIRED COMPONENTS system)
message("----------------------")
message(${Boost_DIR})
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


add_executable(share_memory  src/share_memory_atomic.cpp)
target_link_libraries(share_memory ${Boost_LIBRARIES})
target_link_libraries(share_memory pthread)
target_link_libraries(share_memory rt)


add_executable(atomic  src/atomic.cpp)
target_link_libraries(atomic ${Boost_LIBRARIES})
target_link_libraries(atomic pthread)
target_link_libraries(atomic rt)

add_executable(atomic_test  src/atomic.cpp)
target_link_libraries(atomic_test ${Boost_LIBRARIES})
target_link_libraries(atomic_test pthread)
target_link_libraries(atomic_test rt)

add_executable(allocator  src/allocator.cpp)
target_link_libraries(allocator ${Boost_LIBRARIES})
target_link_libraries(allocator pthread)
target_link_libraries(allocator rt)



add_executable(test  src/test.cpp)
target_link_libraries(test ${Boost_LIBRARIES})
target_link_libraries(test pthread)
target_link_libraries(test rt)


add_executable(construct  src/construct.cpp)
target_link_libraries(construct ${Boost_LIBRARIES})
target_link_libraries(construct pthread)
target_link_libraries(construct rt)


add_executable(share_ptr  src/share_ptr.cpp)
target_link_libraries(share_ptr ${Boost_LIBRARIES})
target_link_libraries(share_ptr pthread)
target_link_libraries(share_ptr rt)