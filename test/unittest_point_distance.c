#include "mtest.h"
#include "point_distance.h"

#define SMALL_TOLERANCE 0.0000000000001

TEST_CASE(point_distance_2d_00_10, {
    // we test the function for 2D points first
    // The distance between (0,0) and (1, 0) should be 1
    MESSAGE("Testing (0,0)(1,0)\n");
    double distance = point_distance_2d(0, 0, 1, 0);
    CHECK_EQ_DOUBLE(distance, 1.0, SMALL_TOLERANCE);
})

// Add the other test cases here:


MAIN_RUN_TESTS(point_distance_2d_00_10)
