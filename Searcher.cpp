//
// Created by Szymon Urbaniak on 29/10/2026.
//

#include "Searcher.h"

#include <iostream>

Searcher::Searcher(const std::string &folderPath) {
    for (const auto &entry: std::filesystem::directory_iterator(folderPath)) {
        this->files.push_back(entry.path());
    }
}

std::vector<int> Searcher::naiveSearch(const std::string &text, const std::string &query) {
    int textLength = text.length();
    int queryLength = query.length();

    int checks = 0;
    std::vector<int> indexes;

    for (int i = 0; i <= textLength - queryLength; i++) {
        for (int j = 0; j < queryLength; j++) {
            checks++;

            if (text[i + j] != query[j]) {
                break;
            }

            if (j == queryLength - 1) {
                indexes.push_back(i);
            }
        }
    }

    return indexes;
}

std::vector<int> Searcher::boyerSearch(const std::string &text, const std::string &query) {
    int textLength = text.length();
    int queryLength = query.length();

    int checks = 0;
    int shift = 0;
    std::vector<int> indexes;
    int badChar[256];
    std::fill_n(badChar, 256, -1);

    for (int i = 0; i < queryLength; i++) {
        badChar[query[i]] = i;
    }

    while (shift <= textLength - queryLength) {
        int j = queryLength - 1;

        while (j >= 0 && query[j] == text[shift + j]) {
            checks++;
            j--;
        }

        if (j >= 0) checks++;

        if (j < 0) {
            indexes.push_back(shift);
            if (shift + queryLength < textLength) {
                shift += queryLength - badChar[text[shift + queryLength]];
            } else {
                shift++;
            }
        } else {
            shift += std::max(1, j - badChar[text[shift + j]]);
        }
    }

    return indexes;
}

std::string Searcher::formatAsLog(std::string text, std::string filename) {
    return "\033[90m[" + std::to_string(std::chrono::high_resolution_clock::now().time_since_epoch().count()) +
        "]\033[36m[" + filename + "]\033[0m " + text;
}

std::string Searcher::formatOccurencies(std::vector<int> indexes) {
    std::string output;
    if (indexes.empty()) {
        output += "No occurencies were found.\n";
    } else if (indexes.size() <= 250) {
        output += "Occurencies found at indexes:\n";
        for (int index: indexes) {
            output += std::to_string(index) + "\n";
        }
    } else {
        output += "Large number (" + std::to_string(indexes.size()) + ") of occurencies was found.\n";
    }
    return output;
}
