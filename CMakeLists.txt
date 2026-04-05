cmake_minimum_required(VERSION 3.5)
project(lab_3_2026 CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab_3_2026
        main.cpp
        University.h
        University.cpp
        LinkedList.h
        LinkedList.cpp
        ChainHashTableStat.h
        ChainHashTableStat.cpp
        ChainHashTableDynamic.h
        ChainHashTableDynamic.cpp
        HashNode.h
        HashNode.cpp
        Testing.cpp
        Utils.h
        Utils.cpp
        Testing.h
        BaseHashTable.h)
