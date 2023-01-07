cmake_minimum_required(VERSION 3.24)
project(SoundProcessor)

set(CMAKE_CXX_STANDARD 14)

add_executable(SoundProcessor main.cpp state.h parser.cpp parser.h converter.cpp converter.h editor.cpp editor.h WAV_channel.cpp WAV_channel.h)
