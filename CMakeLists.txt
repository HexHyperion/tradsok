cmake_minimum_required(VERSION 4.1)
project(ThreadedSearch)

set(CMAKE_CXX_STANDARD 20)

add_executable(ThreadedSearch main.cpp
        SyncSearcher.cpp
        SyncSearcher.h
        Searcher.cpp
        Searcher.h
        ThreadedSearcher.cpp
        ThreadedSearcher.h)
