cmake_minimum_required(VERSION 3.19)
project(Small_Neural_Network)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Small_Neural_Network
        MainApp.cpp accessingData.cpp accessingData.h Network.cpp Network.h Neuron.cpp Neuron.h Sigmoid.cpp Sigmoid.h
        )
