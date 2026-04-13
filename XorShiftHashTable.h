#ifndef XORSHIFTHASHTABLE_H
#define XORSHIFTHASHTABLE_H

#include "ChainHashTableDynamic.h"

class XorShiftHashTable : public ChainHashTableDynamic {
protected:
    int hash(long long key) const override {
        // Проста комбінація бітових зсувів для "перемішування" бітів ключа
        unsigned long long x = static_cast<unsigned long long>(key);
        x ^= (x >> 33);
        x *= 0xff51afd7ed558ccdLLU;
        x ^= (x >> 33);
        
        return static_cast<int>(x % M);
    }

public:
    XorShiftHashTable(int initialCapacity = 10) 
        : ChainHashTableDynamic(initialCapacity) {
        implementationName = "Dynamic Chaining (XOR/Shift Hash)";
    }
};

#endif