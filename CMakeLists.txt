cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
project(MyNeuralNetwork VERSION 0.1.0)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "src/*")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(PROJECT_LIBS 
    ${PROJECT_LIBS}
    ${CMAKE_DL_LIBS}
    ${OpenCV_LIBS})

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)

