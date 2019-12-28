#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>

#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "factory.h"
#include "handler.h"

enum Commands{
    cmd_quit,
    cmd_sqr,
    cmd_rect,
    cmd_trpz,
};

void handle(std::vector<std::unique_ptr<figure>>& figures, int buffer_size, std::condition_variable& cv_mtx1, std::condition_variable& cv_mtx2, std::mutex& mtx, bool& stop_thrd) {
	std::unique_lock<std::mutex> lock(mtx);
	cv_mtx2.notify_all();
	std::vector<std::unique_ptr<handler>> handlers;

	handlers.push_back(std::make_unique<file_handler>());
	handlers.push_back(std::make_unique<console_handler>());
	while (!(stop_thrd)) {
		cv_mtx1.wait(lock);
		//std::cout << figures.size() << std::endl;
		if (figures.size() != 0) {
			for (int i = 0; i < handlers.size(); ++i) {
				handlers[i]->execute(figures);
			}
		}
		figures.clear();
		cv_mtx2.notify_all();
	}
	return;
}
int main(int argc, char* argv[]) {
	if (argc != 2)
		return 1;
	std::condition_variable cv_mtx1;
	std::condition_variable cv_mtx2;
	std::vector<std::unique_ptr<figure>> figures;
	std::unique_ptr<factory> my_factory;
	std::mutex mtx;
	std::unique_lock<std::mutex> lock(mtx);
	int buffer_size, command;
	buffer_size = std::stoi(argv[1]);
	bool stop_thrd = false;
	std::thread handler(handle, std::ref(figures), buffer_size, std::ref(cv_mtx1), std::ref(cv_mtx2), ref(mtx), std::ref(stop_thrd));
	cv_mtx2.wait(lock);
	while (true) {
		for (int i = 0; i < buffer_size; ++i) {
			std::cout << "1 - Square" << std::endl;
			std::cout << "2 - Rectangle" << std::endl;
			std::cout << "3 - Trapezoid" << std::endl;
			std::cin >> command;
			switch (command) {
			case cmd_sqr :
				my_factory = std::make_unique<square_factory>();
				figures.push_back(my_factory->build(std::cin));
				break;
			case cmd_rect :
				my_factory = std::make_unique<rectangle_factory>();
				figures.push_back(my_factory->build(std::cin));
				break;
			case cmd_trpz :
				my_factory = std::make_unique<trapezoid_factory>();
				figures.push_back(my_factory->build(std::cin));
				break;
			}
		}
		cv_mtx1.notify_all();
		cv_mtx2.wait(lock);
		std::cout << "The buffer is filled" << std::endl;
		std::cout << "Continue? 'y' - Yes 'n' - No" << std::endl;
		char answer;
		std::cin >> answer;
		if (answer != 'y')
			break;
	}
	stop_thrd = true;
	cv_mtx1.notify_all();
	lock.unlock();
	handler.join();
	return 0;
}