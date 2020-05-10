cmake_minimum_required(VERSION 3.15)
project(UltraSerial)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib)

LINK_DIRECTORIES(/usr/local/lib)
include_directories(/usr/local/include)

add_executable(UltraSerial src/main.cpp src/Transmitter.cpp src/Transmitter.h src/Config.h src/Receiver.cpp src/Receiver.h)
target_link_libraries(UltraSerial portaudio)
