#include "CommandHandler.h"
#include <iostream>

void CommandHandler::init(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: guit init <name>" << std::endl;
        return;
    }
    std::string name = argv[2];
    std::cout << "Initializing repository: " << name << std::endl;
    // Aquí iría la lógica para inicializar el repositorio
}

void CommandHandler::add(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: guit add <file>" << std::endl;
        return;
    }
    std::string file = argv[2];
    std::cout << "Adding file: " << file << std::endl;
    // Aquí iría la lógica para agregar el archivo
}
