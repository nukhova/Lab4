cmake_minimum_required(VERSION 3.21)
project(Lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab4 main.cpp Product.cpp Product.h Position.cpp Position.h Order.cpp Order.h Client.cpp Client.h PriceBase.cpp PriceBase.h)
