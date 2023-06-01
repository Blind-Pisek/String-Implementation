cmake_minimum_required(VERSION 3.0.0)
project(OWN-STRING-IMPLEMENTATION VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(String-Implementation)

add_executable(${PROJECT_NAME} main.cpp)


# Link libraries into project.
target_link_libraries( ${PROJECT_NAME}
    STL-STR-IMPLEMENTATION-LIB
    )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
