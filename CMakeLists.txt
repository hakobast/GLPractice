cmake_minimum_required(VERSION 3.4)
project(CLearn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Sources
file(GLOB_RECURSE LIB_SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
file(GLOB_RECURSE LIB_HEADERS ${CMAKE_CURRENT_LIST_DIR}/src/*.h)

set(SOURCE_FILES src/main.cpp ${LIB_SOURCES} ${LIB_HEADERS})

add_executable(CLearn ${SOURCE_FILES})

# Add project modules path
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

# Find SMFL
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(CLearn ${SFML_LIBRARIES})
endif()

# Find OpenGL
find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIRS})
    target_link_libraries(CLearn ${OPENGL_LIBRARIES})
endif()

# Find GLM
find_package(GLM REQUIRED)
if(GLM_FOUND)
    include_directories(${GLM_INCLUDE_DIRS})
    target_link_libraries(CLearn ${GLM_LIBRARIES})
endif()
