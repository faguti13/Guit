#include <iostream>
#include <curl/curl.h>
#include <string>
#include "CommandHandler.h"

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void makeGetRequest() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5122/weatherforecast");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        std::cout << "GET Response: " << readBuffer << std::endl;
    }
    curl_global_cleanup();
}

void makePostRequest(const std::string& command) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    std::string url = "http://localhost:5122/commands/" + command;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        // Aquí puedes enviar datos adicionales si es necesario
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        else
            std::cout << "Response from server: " << readBuffer << std::endl;
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: guit <command> [options]" << std::endl;
        return 1;
    }

    std::string command = argv[1];
    CommandHandler handler;

    if (command == "init") {
        handler.init(argc, argv);
        makePostRequest("init");
    } else if (command == "add") {
        handler.add(argc, argv);
        makePostRequest("add");
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
    }

    return 0;
}