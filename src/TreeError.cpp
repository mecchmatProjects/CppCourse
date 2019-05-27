#include "TreeError.h"
#include <iostream>
#include <fstream>

void TreeError::Message() {
    std::cout << "TreeError: ";
    if (code == 1) {
        std::cout << "Can't find a file for output";
    } else {
        std::cout << "unknown fail. Please contact developer";
    }
}

void TreeError::Message(char *log_file) {
    try {
        std::fstream file(log_file, std::ios::app);

        if (!file) throw "Logging failed";

        file.seekg(std::ios_base::end);
        file << "TreeError: ";
        if (code == 1) {
            file << "Can't find a file for output" << std::endl;
        } else {
            file << "unknown fail. Please contact developer";
        }
    } catch (const char fail){
        std::cout << fail << std::endl;
        Message();
    }
}