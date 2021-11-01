cmake_minimum_required(VERSION 3.20)
project(designPrinciples)

set(CMAKE_CXX_STANDARD 14)

add_executable(designPrinciples main.cpp SOLID/LiskovSubPrinc.cpp SOLID/LiskovSubPrinc.h SOLID/InterfaceSegPrinc.cpp SOLID/InterfaceSegPrinc.h SOLID/DependancyInversionPrinc.cpp SOLID/DependancyInversionPrinc.h SOLID/OpenClosed.cpp SOLID/OpenClosed.h Builder/builder.cpp Builder/builder.h)
