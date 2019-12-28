#ifndef D_SQUARE_H
#define D_SQUARE_H

#include "figure.h"

#include<memory>
#include<array>

struct square : figure{
private:
    std::array<point, 4> vertices;
public:
    void read(std::istream& is) override;
    void print(std::ostream& os) const override;
};
#endif //D_SQUARE_H
