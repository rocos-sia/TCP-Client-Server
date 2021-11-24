cmake_minimum_required(VERSION 3.10)

project(C++)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)


find_package(Boost REQUIRED COMPONENTS system thread)


add_executable(write  src/write.cpp)
target_include_directories(write  PRIVATE  ${Boost_INCLUDE_DIRS})
target_link_libraries(write   PRIVATE   ${Boost_LIBRARIES} pthread rt m  )

add_executable(read  src/read.cpp)
target_include_directories(read  PRIVATE  ${Boost_INCLUDE_DIRS})
target_link_libraries(read   PRIVATE   ${Boost_LIBRARIES} pthread rt m  )

add_executable(share_memory  src/share_memory_atomic.cpp)
target_include_directories(share_memory  PRIVATE  ${Boost_INCLUDE_DIRS})
target_link_libraries(share_memory   PRIVATE   ${Boost_LIBRARIES} pthread rt m  )

add_executable(atomic  src/atomic.cpp)
target_include_directories(atomic  PRIVATE  ${Boost_INCLUDE_DIRS})
target_link_libraries(atomic   PRIVATE   ${Boost_LIBRARIES} pthread rt m  )


add_executable(atomic_test  src/atomic.cpp)
target_include_directories(atomic_test  PRIVATE  ${Boost_INCLUDE_DIRS})
target_link_libraries(atomic_test   PRIVATE   ${Boost_LIBRARIES} pthread rt m  )

add_executable(allocator  src/allocator.cpp)
target_include_directories(allocator  PRIVATE  ${Boost_INCLUDE_DIRS})
target_link_libraries(allocator   PRIVATE   ${Boost_LIBRARIES} pthread rt m  )


add_executable(test  src/test.cpp)
target_include_directories(test  PRIVATE  ${Boost_INCLUDE_DIRS})
target_link_libraries(test   PRIVATE   ${Boost_LIBRARIES} pthread rt m  )

add_executable(construct  src/construct.cpp)
target_include_directories(construct  PRIVATE  ${Boost_INCLUDE_DIRS})
target_link_libraries(construct   PRIVATE   ${Boost_LIBRARIES} pthread rt m  )

add_executable(share_ptr  src/share_ptr.cpp)
target_include_directories(share_ptr  PRIVATE  ${Boost_INCLUDE_DIRS})
target_link_libraries(share_ptr   PRIVATE   ${Boost_LIBRARIES} pthread rt m  )

add_executable(TCP_client  src/TCP_client.cpp)
target_include_directories(TCP_client  PRIVATE  ${Boost_INCLUDE_DIRS})
target_link_libraries(TCP_client   PRIVATE   ${Boost_LIBRARIES} pthread rt m  )


add_executable(TCP_server  src/TCP_server.cpp)
target_include_directories(TCP_server  PRIVATE  ${Boost_INCLUDE_DIRS})
target_link_libraries(TCP_server   PRIVATE   ${Boost_LIBRARIES} pthread rt m  )