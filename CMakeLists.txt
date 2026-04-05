cmake_minimum_required(VERSION 3.15...4.0)

project(
  ${SKBUILD_PROJECT_NAME}
  VERSION ${SKBUILD_PROJECT_VERSION}
  LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 20)

find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

python_add_library(_tiny_math MODULE src/tiny_math.cpp WITH_SOABI)
target_link_libraries(_tiny_math PRIVATE pybind11::headers)

target_compile_definitions(_tiny_math PRIVATE VERSION_INFO=${PROJECT_VERSION})

install(TARGETS _tiny_math DESTINATION tiny_math)
