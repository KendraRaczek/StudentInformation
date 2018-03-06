cmake_minimum_required(VERSION 3.8)
project(Assignment4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Student.cpp UndergradStudent.cpp GradStudent.cpp processStudent.cpp students.txt)
add_executable(Assignment4 ${SOURCE_FILES} Student.cpp UndergradStudent.cpp GradStudent.cpp processStudent.cpp students.txt)