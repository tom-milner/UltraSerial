cmake_minimum_required(VERSION 3.15)
project(UltraSerial)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib)

LINK_DIRECTORIES(/usr/local/lib)
include_directories(/usr/local/include)

add_executable(UltraSerial src/RingBuffer.h src/main.cpp src/Transmitter.cpp src/Transmitter.h src/Config.h src/Receiver.cpp src/Receiver.h )
target_link_libraries(UltraSerial portaudio)
target_link_libraries(UltraSerial fftw3)
#
#set_target_properties(UltraSerial PROPERTIES
#        MACOSX_BUNDLE TRUE
#        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist
#        )
