#ifndef MULTIPLICATIONHASHTABLE_H
#define MULTIPLICATIONHASHTABLE_H

#include "ChainHashTableDynamic.h"
#include <cmath>

class MultiplicationHashTable : public ChainHashTableDynamic {
protected:
    // Перевизначаємо тільки хеш-функцію
    int hash(long long key) const override {
        const double A = 0.6180339887; // Золотий перетин
        double fraction = (key * A) - std::floor(key * A);
        return static_cast<int>(M * fraction);
    }

public:
    MultiplicationHashTable(int initialCapacity = 10) 
        : ChainHashTableDynamic(initialCapacity) {
        implementationName = "Dynamic Chaining (Multiplication Hash)";
    }
};

#endif