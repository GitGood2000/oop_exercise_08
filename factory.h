#ifndef D_FACTORY_H
#define D_FACTORY_H

#include<iostream>

#include"figure.h"
#include"square.h"
#include"rectangle.h"
#include"trapezoid.h"

struct factory {
public:
	virtual std::unique_ptr<figure> build(std::istream& is) = 0;
	virtual ~factory() = default;
};

struct square_factory : factory {
	std::unique_ptr<figure> build(std::istream& is) override{
		std::unique_ptr<square> temp;
		temp = std::make_unique<square>();
		temp->read(is);
		return std::move(temp);
	}
};
struct rectangle_factory : factory {
	std::unique_ptr<figure> build(std::istream& is) override {
		std::unique_ptr<rectangle> temp;

		temp = std::make_unique<rectangle>();
		temp->read(is);
		return std::move(temp);
	}
};
struct trapezoid_factory : factory {
	std::unique_ptr<figure> build(std::istream& is) override {
		std::unique_ptr<trapezoid> temp;

		temp = std::make_unique<trapezoid>();
		temp->read(is);
		return std::move(temp);
	}
};

#endif //D_FACTORY_H
