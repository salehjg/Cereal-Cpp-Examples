cmake_minimum_required(VERSION 3.10)
project(CerealCppExamples)
include_directories(inc)
find_package(cereal REQUIRED)
add_executable(CerealCppExamples
        src/main.cpp
        src/CSymLink.cpp
        src/CConst.cpp
        src/CSymbol.cpp
        )

target_link_libraries(CerealCppExamples cereal::cereal)
