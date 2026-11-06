//
// Created by Szymon Urbaniak on 29/10/2026.
//

#ifndef THREADEDSEARCH_SEARCHER_H
#define THREADEDSEARCH_SEARCHER_H
#include <filesystem>
#include <vector>

class Searcher {
protected:
    std::vector<std::filesystem::path> files;
public:
    Searcher(const std::string &folderPath);

    virtual ~Searcher() = default;

    virtual void search(const std::string &query) = 0;
    static std::vector<int> naiveSearch(const std::string &text, const std::string &query);
    static std::vector<int> boyerSearch(const std::string &text, const std::string &query);
    static std::string formatAsLog(std::string text, std::string filename);
    static std::string formatOccurencies(std::vector<int> indexes);
};

#endif //THREADEDSEARCH_SEARCHER_H