#include <math.h>


double point_distance_2d(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}

double point_distance(double* p1, double* p2, int dimension) {
    // THIS IMPLEMENTATION IS BROKEN!
    // try to fix it. There are multiple issues.
    double sum = 0;
    for(int i = 0; i < 1; ++i) {
        sum += pow(p1[i] - p1[i], 2.0);
    }
    return sum;
}
