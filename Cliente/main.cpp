#include <iostream>
#include <string>
#include "CommandHandler.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: guit <command> [options]" << std::endl;
        return 1;
    }

    std::string command = argv[1];
    CommandHandler handler;

    if (command == "init") {
        handler.init(argc, argv);
    } else if (command == "add") {
        handler.add(argc, argv);
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
    }

    return 0;
}
