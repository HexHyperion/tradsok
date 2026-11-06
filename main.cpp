#include <chrono>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "SyncSearcher.h"
#include "ThreadedSearcher.h"

int main() {
    std::string path = "/Users/szymon/CLionProjects/ThreadedSearch/text";
    std::string query;

    std::cout << "====== INPUT THE PATTERN TO FIND: ======" << std::endl;
    std::cin >> query;
    std::cout << std::endl;

    std::cout << Searcher::formatAsLog("====== STARTING SYNCHRONOUS SEARCH ======\n", path);
    auto searcher = SyncSearcher(path);
    auto syncSearchStart = std::chrono::high_resolution_clock::now();
    searcher.search(query);
    auto syncSearchEnd = std::chrono::high_resolution_clock::now();
    auto syncSearchDuration = std::chrono::duration_cast<std::chrono::milliseconds>(syncSearchEnd - syncSearchStart);

    std::cout << Searcher::formatAsLog("Synchronous search finished, execution took " +
        std::to_string(syncSearchDuration.count()) + " ms.\n", path);
    std::cout << std::endl;


    std::cout << Searcher::formatAsLog("====== STARTING THREADED SEARCH ======\n", path);
    auto tSearcher = ThreadedSearcher(path);
    auto threadSearchStart = std::chrono::high_resolution_clock::now();
    tSearcher.search(query);
    auto threadSearchEnd = std::chrono::high_resolution_clock::now();
    auto threadSearchDuration = std::chrono::duration_cast<std::chrono::milliseconds>(threadSearchEnd - threadSearchStart);

    std::cout << Searcher::formatAsLog("Threaded search finished, execution took " +
        std::to_string(threadSearchDuration.count()) + " ms.\n", path);

    return 0;
}
