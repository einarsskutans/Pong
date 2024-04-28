#ifndef UTIL_H
#define UTIL_H

#include <vector>

struct Center {
    Center();
    Center(double px, double py);
    ~Center();
    double x, y;
};
struct Color {
    Color();
    Color(int pr, int pg, int pb);
    ~Color();
    int r, g, b;
};

#endif