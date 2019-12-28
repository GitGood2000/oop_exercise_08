#ifndef D_FIGURE_H
#define D_FIGURE_H

#include<iostream>
#include<fstream>

struct figure {
    virtual void read(std::istream& is) = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual ~figure() = default;
};

struct point {
    int x, y;
};

#endif //D_FIGURE_H
