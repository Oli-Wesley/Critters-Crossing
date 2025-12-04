#include "S_GlobalData.h"
#include <iostream>
#include <sstream>

void S_GlobalData::start()
{
    std::ifstream loadFile("../data/SaveData/Score.txt");

    high_score = 0; // default

    if (loadFile.is_open()) {
        std::string text;
        if (std::getline(loadFile, text)) {
            std::stringstream ss(text);
            ss >> high_score;            
            if (ss.fail()){
                high_score = 0; // fallback if file contains garbage
                std::cout << "file read, but wasn't a number, high_score: 0";
            }
            else {
                std::cout << "read high_score from file: " << high_score << std::endl;
            }
        }
    }
    else {
        // File did not exist — create it with default score
        std::ofstream createFile("../data/SaveData/Score.txt");
        createFile << "0";
        std::cout << "file not found, creating file, high_score: 0 \n";
    }
    loadFile.close();
}

void S_GlobalData::onDestroy()
{
    // Truncate file and write score
    std::ofstream saveFile("../data/SaveData/Score.txt", std::ios::trunc);

    if (saveFile.is_open()) {
        saveFile << high_score;
        std::cout << "saved high_score to file: " << high_score << std::endl;
    }
    saveFile.close();
}