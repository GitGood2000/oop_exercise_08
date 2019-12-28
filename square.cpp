#include "square.h"

#include<iostream>
#include<fstream>
#include<cassert>

void square::read(std::istream& is) {
	for (int i = 0; i < 4; i++) {
		is >> vertices[i].x >> vertices[i].y;
	}
        assert(((vertices[1].x - vertices[0].x)*(vertices[3].x - vertices[0].x))+((vertices[1].y - vertices[0].y)*(vertices[3].y - vertices[0].y)) == 0);
        assert(((vertices[2].x - vertices[1].x)*(vertices[0].x - vertices[1].x))+((vertices[2].y - vertices[1].y)*(vertices[0].y - vertices[1].y)) == 0);
        assert(((vertices[3].x - vertices[2].x)*(vertices[1].x - vertices[2].x))+((vertices[3].y - vertices[2].y)*(vertices[1].y - vertices[2].y)) == 0);
        assert((vertices[1].x - vertices[0].x) == (vertices[0].y - vertices[3].y));
        assert((vertices[2].x - vertices[1].x) == (vertices[1].y - vertices[0].y));
        assert((vertices[3].x - vertices[2].x) == (vertices[2].y - vertices[1].y));
}
void square::print(std::ostream& os) const {
    os << "Square:" << std::endl;
	for (int i = 0; i < 4; i++) {
		os << vertices[i].x << ' ' << vertices[i].y << std::endl;
	}
}