#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265359;
double gcd(double x, double y)
{
    return fabs(y) < 1e-4 ? x : gcd(y, fmod(x, y));
}
double min_area_of_polygon(double Ax, double Ay, double Bx,
                            double By, double Cx, double Cy)
{
    double a, b, c, Radius, Angle_A, Angle_B, Angle_C,
                              semiperimeter, n, area;

    a = sqrt((Bx - Cx) * (Bx - Cx) + (By - Cy) * (By - Cy));
    b = sqrt((Ax - Cx) * (Ax - Cx) + (Ay - Cy) * (Ay - Cy));
    c = sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By));
    semiperimeter = (a + b + c) / 2;
    double area_triangle = sqrt(semiperimeter * (semiperimeter - a)
                                * (semiperimeter - b)
                                * (semiperimeter - c));
    Radius = (a * b * c) / (4 * area_triangle);
    Angle_A = acos((b * b + c * c - a * a) / (2 * b * c));
    Angle_B = acos((a * a + c * c - b * b) / (2 * a * c));
    Angle_C = acos((b * b + a * a - c * c) / (2 * b * a));
    n = pi / gcd(gcd(Angle_A, Angle_B), Angle_C);
    area = (n * Radius * Radius * sin((2 * pi) / n)) / 2;

    return area;
}

int main()
{

    double Ax, Ay, Bx, By, Cx, Cy;
    Ax = 0.00;
    Ay = 0.00;
    Bx = 1.00;
    By = 1.00;
    Cx = 0.00;
    Cy = 1.00;

    cout<< min_area_of_polygon(Ax, Ay, Bx, By, Cx, Cy);
    return 0;
}
