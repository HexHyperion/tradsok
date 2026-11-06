//
// Created by Szymon Urbaniak on 29/10/2026.
//

#include "SyncSearcher.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::ifstream sfin;

SyncSearcher::SyncSearcher(const std::string &folderPath) : Searcher(folderPath) {}

void SyncSearcher::search(const std::string &query) {
    for (const auto & file : files) {
        sfin.open(file);

        if (sfin.good()) {
            std::stringstream stream;
            std::vector<int> naive, boyer;

            stream << sfin.rdbuf();
            std::string text = stream.str();
            std::cout << formatAsLog("File " + file.string() + " loaded.\n", file.filename());


            // NAIVE SEARCH TEST
            std::cout << formatAsLog("Starting the naive search...\n", file.filename());

            auto naiveSearchStart = std::chrono::high_resolution_clock::now();
            naive = naiveSearch(text, query);
            auto naiveSearchEnd = std::chrono::high_resolution_clock::now();
            auto naiveSearchDuration = duration_cast<std::chrono::milliseconds>(naiveSearchEnd - naiveSearchStart);

            std::cout << formatAsLog("Naive search finished, execution took " +
                std::to_string(naiveSearchDuration.count()) + " ms.\n", file.filename());
            std::cout << formatAsLog(formatOccurencies(naive), file.filename());


            // BOYER-MOORE SEARCH TEST
            std::cout << formatAsLog("Starting the Boyer-Moore search...\n", file.filename());

            auto boyerSearchStart = std::chrono::high_resolution_clock::now();
            boyer = boyerSearch(text, query);
            auto boyerSearchEnd = std::chrono::high_resolution_clock::now();
            auto boyerSearchDuration = duration_cast<std::chrono::milliseconds>(boyerSearchEnd - boyerSearchStart);

            std::cout << formatAsLog("Boyer-Moore search finished, execution took " +
                std::to_string(boyerSearchDuration.count()) + " ms.\n", file.filename());
            std::cout << formatAsLog(formatOccurencies(boyer), file.filename());

            sfin.close();
        }
        else {
            std::cout << formatAsLog("Program failed to open file " + file.string() + "!\n", file.filename());
        }
    }
}
