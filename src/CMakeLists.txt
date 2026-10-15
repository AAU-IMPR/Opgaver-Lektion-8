
# This defines a library `point_distance` with the source file `point_distance.c`
add_library(point_distance point_distance.c)
target_link_libraries(point_distance m)
target_include_directories(point_distance PUBLIC .)

# TODO: When you want to work in the puzzle (Opgave D), uncomment the following line:
# add_executable(puzzle puzzle.c)

add_executable(menu menu.c)

add_executable(opgave-f opgave-f.c)
target_link_libraries(opgave-f m)
