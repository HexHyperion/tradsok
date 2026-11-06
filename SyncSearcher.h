//
// Created by Szymon Urbaniak on 29/10/2026.
//

#ifndef THREADEDSEARCH_SYNCSEARCHER_H
#define THREADEDSEARCH_SYNCSEARCHER_H
#include <filesystem>

#include "Searcher.h"

class SyncSearcher : public Searcher {
public:
    SyncSearcher(const std::string &folderPath);
    void search(const std::string &query) override;

    ~SyncSearcher() override = default;
};

#endif //THREADEDSEARCH_SYNCSEARCHER_H