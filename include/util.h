#ifndef UTIL_H
#define UTIL_H

#include <vector>

struct Center {
    Center();
    Center(int px, int py);
    ~Center();
    int x, y;
};
struct Color {
    Color();
    Color(int pr, int pg, int pb);
    ~Color();
    int r, g, b;
    static std::vector<Color> Colors;
};

#endif