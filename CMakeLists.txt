cmake_minimum_required(VERSION 3.14)
project(Algorithms_Sedgewick)

set(CMAKE_CXX_STANDARD 11)

include_directories(math)
include_directories(base/sample)

add_executable(Algorithms_Sedgewick main.cpp base/exercise/Matrix.cpp base/sample/Chapter1Sample.cpp base/sample/Chapter1Sample.h base/exercise/MathFilter.cpp base/exercise/MathFilter.h)