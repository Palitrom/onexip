 
cmake_minimum_required(VERSION 3.5)

project(onexip LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(producer producer.cpp)

add_executable(consumer consumer.cpp)
