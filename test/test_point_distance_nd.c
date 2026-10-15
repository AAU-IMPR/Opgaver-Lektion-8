#include <stdio.h>
#include <assert.h>
#include "point_distance.h"


void dimension_2_test() {
    double point1[2] = {0,0};
    double point2[2] = {0,0};
    assert(point_distance(point1, point2, 2) == 0);

    point1[0] = 1;
    point1[1] = 0;
    point2[0] = 0;
    point2[1] = 0;

    assert(point_distance(point1, point2, 2) == 1);

    point1[0] = 10;
    point1[1] = 10;
    point2[0] = 0;
    point2[1] = 0;

    double distance = point_distance(point1, point2, 2);
    assert(distance > 14 && distance < 15);

}

void dimension_4_test() {
    double point1[4] = {0,0, 0, 0};
    double point2[4] = {0,0, 0, 0};
    assert(point_distance(point1, point2, 3) == 0);


    point1[0] = 0;
    point1[1] = 0;
    point1[2] = 0;
    point1[3] = 0;
    point2[0] = 0;
    point2[1] = 0;
    point2[2] = 3;
    point2[3] = 0;

    assert(point_distance(point1, point2, 3) == 3);

    point1[0] = 0;
    point1[1] = 0;
    point1[2] = 0;
    point1[3] = 0;
    point2[0] = 1;
    point2[1] = 1;
    point2[2] = 1;
    point2[3] = 1;
    double distance = point_distance(point1, point2, 4);
    assert(distance == 2);
}

int main(void) {
    dimension_2_test();
    dimension_4_test();
    return 0;
}
