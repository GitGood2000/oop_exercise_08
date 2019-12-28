#ifndef D_FACTORY_H
#define D_FACTORY_H

#include<iostream>
#include<memory>

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
	std::unique_ptr<figure> build(std::istream& is) override {
		std::unique_ptr<square> t_sqr;
		t_sqr = std::make_unique<square>();
		t_sqr->read(is);
		return std::move(t_sqr);
	}
};

struct rectangle_factory : factory {
	std::unique_ptr<figure> build(std::istream& is) override {
		std::unique_ptr<rectangle> t_rect;
		t_rect = std::make_unique<rectangle>();
		t_rect->read(is);
		return std::move(t_rect);
	}
};

struct trapezoid_factory : factory {
	std::unique_ptr<figure> build(std::istream& is) override {
		std::unique_ptr<trapezoid> t_trpz;
		t_trpz = std::make_unique<trapezoid>();
		t_trpz->read(is);
		return std::move(t_trpz);
	}
};

#endif //D_FACTORY_H
