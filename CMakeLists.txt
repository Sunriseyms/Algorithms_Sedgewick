cmake_minimum_required(VERSION 3.14)
project(Algorithms_Sedgewick)

set(CMAKE_CXX_STANDARD 14)

include_directories(base/sample)
include_directories(base/exercise)
include_directories(ch103/sample)
include_directories(ch103/exercise)
include_directories(ch103/extra)

add_executable(Algorithms_Sedgewick main.cpp base/exercise/Matrix.cpp base/sample/Chapter1Sample.cpp base/sample/Chapter1Sample.h base/exercise/MathFilter.cpp base/exercise/MathFilter.h ch103/sample/CustomizeStack.h base/KnowledgePoint/SmartPointDemo.cpp base/KnowledgePoint/SmartPointDemo.h ch103/extra/MathematicalExpression.cpp ch103/extra/MathematicalExpression.h ch103/exercise/Ech103.cpp ch103/exercise/Ech103.h ch103/extra/RingBufferFullFlag.h ch103/extra/RingBufferWasteOneSlot.h ch103/extra/RingBufferMirrorIndicator.h)