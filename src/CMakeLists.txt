cmake_minimum_required(VERSION 3.28)
project(TheGarden)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wpedantic --debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

find_package(SDL2 REQUIRED)

file(GLOB GARDEN_SRC
     "*.cpp"
)

file(GLOB EXTERN_INCLUDE_DIRS
     "../extern/*/include"
)

file(GLOB EXTERN_LIB_DIRS
     "../extern/*/lib"
)

#message(${EXTERN_INCLUDE_DIRS})
#message(${EXTERN_LIB_DIRS})

message(${GARDEN_SRC})

include_directories(${SDL2_INCLUDE_DIRS} ${EXTERN_INCLUDE_DIRS})

add_executable(TheGarden ${GARDEN_SRC})

target_link_directories(TheGarden PUBLIC ${EXTERN_LIB_DIRS})
target_link_libraries(TheGarden ${SDL2_LIBRARIES} SDL2_image)
