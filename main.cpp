#include <iostream>
#include <math.h>
#include <iomanip>
#include <float.h>

long double distanceBetweenTwoPoints(std::pair<long double, long double> point1, std::pair<long double, long double> point2) {
    return sqrt(pow(point1.first - point2.first, 2) + pow(point1.second - point2.second, 2));
}

int main() {
    unsigned int n;
    while (std::cin >> n and n != 0) {
        std::pair<long double, long double> points[n];
        long double minDistance = DBL_MAX;
        for (unsigned int i = 0; i < n; i++) std::cin >> points[i].first >> points[i].second;
        for (unsigned int i = 0; i < n; i++)
            for (unsigned int j = i + 1; j < n; j++)
                minDistance = std::min(distanceBetweenTwoPoints(points[i], points[j]), minDistance);
        if (minDistance < 10000)
            std::cout << std::fixed << std::setprecision(4) << minDistance << std::endl;
        else
            printf("INFINITY\n");
    }
    return 0;
}