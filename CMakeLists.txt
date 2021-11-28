cmake_minimum_required(VERSION 3.20)
project(Warehouse2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Warehouse2 main.cpp Interfaces.h Warehouse.cpp Warehouse.h
        Shop.cpp Shop.h Factory.cpp Factory.h Generator.cpp Generator.h Delivery.cpp Delivery.h Item.cpp Item.h Statistics.h Statistics.cpp)
