cmake_minimum_required(VERSION 3.10)

project(C++)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)


find_package(Boost REQUIRED COMPONENTS system thread chrono)


add_executable(TCP_client  src/TCP_client.cpp)
target_include_directories(TCP_client  PRIVATE  ${Boost_INCLUDE_DIRS})
target_link_libraries(TCP_client   PRIVATE   ${Boost_LIBRARIES} pthread  )


add_executable(TCP_server  src/TCP_server.cpp)
target_include_directories(TCP_server  PRIVATE  ${Boost_INCLUDE_DIRS})
target_link_libraries(TCP_server   PRIVATE   ${Boost_LIBRARIES} pthread  )
