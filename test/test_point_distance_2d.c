#include <stdio.h>
#include <assert.h>
#include "point_distance.h"


int main(void) {
    // we test the function for 2D points first
    // The distance between (0,0) and (1, 0) should be 1
    printf("Testing (0,0)(1,0)\n");
    assert(point_distance_2d(0, 0, 1, 0) == 1.0);

    // The distance between (0,-1) and (0, 1) should be 2
    printf("Testing (0,-1)(1,0)\n");
    assert(point_distance_2d(0, -1, 0, 1) == 2.0);

    printf("Testing (0,0)(0,0)\n");
    // The distance between (0,0) and (0, 0) should be 0
    assert(point_distance_2d(0, 0, 0, 0) == 0);

    printf("Testing (0,0)(10,10)\n");
    // The distance between (0,0) and (10, 10) should be somewhere between 14 and 15
    double diagonal = point_distance_2d(0, 0, 10, 10);
    assert(diagonal > 14.0 && diagonal < 15.0);

    return 0; // if the test gets all the way here, it was successful
}
