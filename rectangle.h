#ifndef D_RECTANGLE_H
#define D_RECTANGLE_H

#include "figure.h"

#include<memory>
#include<array>

struct rectangle : figure{
private:
    std::array<point, 4> vertices;
public:
    void read(std::istream& is) override;
    void print(std::ostream& os) const override;
    void print(std::string& filename) const override;
};
#endif //D_RECTANGLE_H
