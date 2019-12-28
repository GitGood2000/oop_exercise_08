#ifndef D_HANDLER_H
#define D_HANDLER_H

#include<vector>
#include<string>
#include<fstream>
#include"figure.h"

struct handler {
	virtual void execute(std::vector<std::unique_ptr<figure>>& figures) = 0;
	virtual ~handler() = default;
};

struct file_handler : handler {
	void execute(std::vector<std::unique_ptr<figure>>& figures) override {
		static int count_file = 0;
		std::string filename = "";
		++count_file;

		filename = "file_" + std::to_string(count_file) + ".txt";
		std::ofstream file(filename);
		for (int i = 0; i < figures.size(); ++i) {
			figures[i]->print(file);
		}
	}
};
struct console_handler : handler {
	void execute(std::vector<std::unique_ptr<figure>>& figures) override {
		for (int i = 0; i < figures.size(); ++i) {
			figures[i]->print(std::cout);
		}
	}
};

#endif //D_HANDLER_H
