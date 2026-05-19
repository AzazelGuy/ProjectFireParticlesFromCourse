cmake_minimum_required(VERSION 3.15)
project(SDLFireParticles LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} src/main.cpp 
    src/Screen.cpp
    src/Particles.cpp
    src/Swarm.cpp
)


find_package(SDL2 REQUIRED)
if(TARGET SDL2::SDL2)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main SDL2::SDL2)
else()
    target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})
endif()
