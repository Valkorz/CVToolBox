cmake_minimum_required(VERSION 3.10)
project(CVToolBox)

set(CMAKE_C_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/include)

# mlp.c is excluded until the implementation is complete.
set(SOURCES
    src/calclib.c
    src/cllist.c
    src/llist.c
    src/bintree.c
    src/encode.c
    src/hmap.c
    src/queue.c
    src/tmatch.c
    src/csv.c
    src/collections.c
    src/neural.c
    src/perceptron.c
)

add_library(CVToolBox STATIC ${SOURCES})

install(TARGETS CVToolBox DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

# Main demo
add_executable(main main.c)
target_link_libraries(main CVToolBox)

# Examples
#add_executable(perceptronExample examples/perceptronExample.c)
#target_link_libraries(perceptronExample CVToolBox)

#add_executable(csvConversionExample examples/csvConversionExample.c)
#target_link_libraries(csvConversionExample CVToolBox)
