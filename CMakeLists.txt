cmake_minimum_required(VERSION 3.20)

# 1. Project name
project(SimpleSnakeSDL3)

# 2. Setting C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Using FetchContent to get SDL3
include(FetchContent)

FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG main  # Latest version of SDL3
)

# Downloads compiles and makes SDL3 available
FetchContent_MakeAvailable(SDL3)

# 4. Creates executable
add_executable(SimpleSnakeSDL3 main.cpp)

# 5. Link the library
target_link_libraries(SimpleSnakeSDL3 PRIVATE SDL3::SDL3)

# 6. Automatic DLL copy (For Windows)
if(WIN32)
    add_custom_command(TARGET SimpleSnakeSDL3 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3::SDL3>
        $<TARGET_FILE_DIR:SimpleSnakeSDL3>
    )
endif()