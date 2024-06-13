#include "CommandHandler.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <curl/curl.h>

void CommandHandler::init(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: guit init <name>" << std::endl;
        return;
    }
    std::string name = argv[2];
    std::string repoPath = "./" + name; // Ruta relativa donde se creará el repositorio local

    // Verificar si el directorio ya existe
    if (std::filesystem::exists(repoPath)) {
        std::cerr << "Repository '" << name << "' already exists." << std::endl;
        return;
    }

    // Crear el directorio del repositorio
    std::filesystem::create_directory(repoPath);

    // Crear un archivo dentro del directorio del repositorio para simular la base de datos o archivo de configuración
    std::ofstream configFile(repoPath + "/config.txt");
    configFile << "Repository Name: " << name << std::endl;
    configFile.close();

    // Inicializar cURL
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
    if(curl) {
        // Configurar la solicitud POST
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5122/commands/init");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, ("\"" + name + "\"").c_str());

        // Configurar los encabezados
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Realizar la solicitud y obtener la respuesta
        CURLcode res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        // Limpiar
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    curl_global_cleanup();

    std::cout << "Repository '" << name << "' initialized successfully." << std::endl;
}

void CommandHandler::help() {
    std::cout << "guit help - Muestra informacion sobre los comandos disponibles\n\n";
    std::cout << "Comandos:\n\n";

    std::cout << "guit init <name>\n";
    std::cout << "  Crea un nuevo repositorio en el servidor con el nombre especificado.\n";
    std::cout << "  Tambien crea el archivo .guitignore para ignorar archivos del control de versiones.\n\n";

    std::cout << "guit add [-A] [name]\n";
    std::cout << "  Agrega los archivos especificados o todos los archivos (-A) al area de preparacion\n";
    std::cout << "  para el proximo commit. Ignora los archivos listados en .guitignore.\n\n";

    std::cout << "guit commit <mensaje>\n";
    std::cout << "  Envia los archivos preparados al servidor como un nuevo commit.\n";
    std::cout << "  Requiere un mensaje descriptivo. Genera un ID de commit.\n\n";

    std::cout << "guit status [file]\n";
    std::cout << "  Muestra los archivos modificados, agregados o eliminados desde el ultimo commit.\n";
    std::cout << "  Si se especifica un archivo, muestra el historial de cambios de ese archivo.\n\n";

    std::cout << "guit rollback <file> <commit>\n";
    std::cout << "  Restaura un archivo especifico a la version de un commit anterior.\n\n";

    std::cout << "guit reset <file>\n";
    std::cout << "  Deshace los cambios locales en un archivo y lo revierte al ultimo commit.\n\n";

    std::cout << "guit sync <file>\n";
    std::cout << "  Recupera los ultimos cambios del servidor para un archivo.\n";
    std::cout << "  Si hay cambios locales, permite hacer un merge interactivo.\n";
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

void CommandHandler::commit(int argc, char *argv[])
{
}

void CommandHandler::status(int argc, char *argv[])
{
}

void CommandHandler::rollback(int argc, char *argv[])
{
}

void CommandHandler::reset(int argc, char *argv[])
{
}

void CommandHandler::sync(int argc, char *argv[])
{
}
