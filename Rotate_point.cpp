// Rotates a 2D point (x, y) counter-clockwise by θ degrees around the origin.
// Uses long double precision for high-accuracy coordinate rotation.
// printf is used instead of cout to fully support long double (%Lf) formatting.

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

// High-precision definition of PI using long double
long double PI = 3.14159265358979323846264338327950288419716939937510;

int main() {
    long double x = 0, y = 0, theta = 0;

    // Input coordinates and angle in degrees
    cout << "Enter x coordinate -> ";
    cin >> x;
    cout << "Enter y coordinate -> ";
    cin >> y;
    cout << "Enter rotation angle in degrees (positive for counter-clockwise) -> ";
    cin >> theta;

    // Convert angle from degrees to radians
    theta = (PI / 180) * theta;

    // Output result
    // cout is not used for final result because it may not handle long double precision properly.
    // printf with %Lf ensures full precision output for long double variables.
    cout << "After rotating (" << x << ", " << y << ") by " << (180 / PI) * theta << " degrees, the new coordinates are ";
    printf("(%Lf, %Lf)\n", (cos(theta) * x - sin(theta) * y), (sin(theta) * x + cos(theta) * y));

    return 0;
}
