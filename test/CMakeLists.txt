
################
### Opgave A ###
################

# adding test-cases for point distance

# a (series of) tests is by itself a small program
add_executable(test_point_distance_2d test_point_distance_2d.c)
# we need to link with the library we are testing
target_link_libraries(test_point_distance_2d point_distance)

# this is where we actually add the test
# here we could also add some arguments, see https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html
add_test(NAME test_point_distance_2d
        COMMAND test_point_distance_2d)

# let us add a test of the n-dimensional version
add_executable(test_point_distance_nd test_point_distance_nd.c)
# we need to link with the library we are testing
target_link_libraries(test_point_distance_nd point_distance)

# This test is failing! try to fix it (the code in src/point_distance.c)
add_test(NAME test_point_distance_nd
        COMMAND test_point_distance_nd)

# let us add a test of the n-dimensional version, but using inputs
add_executable(test_point_distance_input test_point_distance_nd.c)
# we need to link with the library we are testing
target_link_libraries(test_point_distance_input point_distance)


################
### Opgave B ###
################

# Tilføj selv CMake og CTest kommandoer til dine test i opgave B
# Se ovenfor hvordan det er gjort for opgave A



##################
### Opgave C ###
##################

# 1. Installation of a testing framework (here the simple mtest).
include(../cmake/mtest.cmake)

# 2. Link mtest to the test executable
# let us add unit testing for the point_distance library
add_executable(test_point_distance unittest_point_distance.c)
# we need to link both with the library we are testing and the mtest framework.
target_link_libraries(test_point_distance point_distance mtest)

# 3. Add test cases to CTest (our test framework has a nice macro for that).
discover_tests(test_point_distance)


## Lav selv en ny .c-fil til unit test af time_calc (Opgave B) og brug mtest (eller et andet testing framework) til at skrive disse test.
## ...


