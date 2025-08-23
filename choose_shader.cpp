#include "choose_shader.hpp"

#include <filesystem>
#include <iostream>
#include <vector>

std::string chooseShader()
{
    const std::string directory = "shaders/";
    const std::string extension = ".frag";

    // find files
    std::vector<std::string> files;
    for (const auto& p : std::filesystem::recursive_directory_iterator(directory)) {
        if (p.path().extension() == extension) {
            files.push_back(p.path().stem().string());
        }
    }

    // choose file
    std::cout << "Please select a shader by index:\n";
    const size_t file_count = files.size();
    size_t choice = file_count;
    do {
        for (size_t i = 0; i < file_count; i++) {
            std::cout << '\t' << i << ". " << files[i] << "\n";
        }
        std::cin >> choice;
        if (choice >= file_count) {
            std::cout << "That index is out of bounds. Please try again:\n";
        }
    } while (choice >= file_count);
    return std::string(directory + files[choice] + extension);
}
