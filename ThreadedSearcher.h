//
// Created by Szymon Urbaniak on 29/10/2026.
//

#ifndef THREADEDSEARCH_THREADEDSEARCHER_H
#define THREADEDSEARCH_THREADEDSEARCHER_H
#include <filesystem>

#include "Searcher.h"

class ThreadedSearcher : public Searcher {
public:
    ThreadedSearcher(const std::string &folderPath);
    void search(const std::string &query) override;

    ~ThreadedSearcher() override = default;
};

#endif //THREADEDSEARCH_THREADEDSEARCHER_H