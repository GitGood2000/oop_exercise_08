#ifndef D_TRAPEZOID_H
#define D_TRAPEZOID_H

#include "figure.h"

#include<memory>
#include<array>

struct trapezoid : figure{
private:
    std::array<point, 4> vertices;
public:
    void read(std::istream& is) override;
    void print(std::ostream& os) const override;
};
#endif //D_TRAPEZOID_H
