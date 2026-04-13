#include "OpenAddressingHashTable.h"
#include <iostream>

OpenAddressingHashTable::OpenAddressingHashTable(int initialCapacity) 
    : BaseHashTable("Dynamic Open Addressing (Linear Probing)"), M(initialCapacity), count(0) {
    table = new Entry[M];
}

OpenAddressingHashTable::~OpenAddressingHashTable() {
    delete[] table;
}

int OpenAddressingHashTable::hash(long long key) const {
    return static_cast<int>(key % M);
}

void OpenAddressingHashTable::rehash() {
    int oldM = M;
    Entry* oldTable = table;

    M = oldM * 2;
    table = new Entry[M];
    count = 0;

    for (int i = 0; i < oldM; ++i) {
        if (oldTable[i].status == OCCUPIED) {
            insert(oldTable[i].key, oldTable[i].value);
        }
    }

    delete[] oldTable;
}

void OpenAddressingHashTable::insert(long long key, const University& value) {
    if (static_cast<double>(count) / M >= maxLoadFactor) {
        rehash();
    }

    int index = hash(key);
    
    // Лінійне пробування: шукаємо першу вільну або видалену комірку
    while (table[index].status == OCCUPIED) {
        if (table[index].key == key) {
            table[index].value = value; // Оновлення значення
            return;
        }
        index = (index + 1) % M;
    }

    table[index].key = key;
    table[index].value = value;
    table[index].status = OCCUPIED;
    count++;
}

University* OpenAddressingHashTable::find(long long key) {
    int index = hash(key);
    int startIndex = index;

    while (table[index].status != EMPTY) {
        if (table[index].status == OCCUPIED && table[index].key == key) {
            return &table[index].value;
        }
        index = (index + 1) % M;
        if (index == startIndex) break; // Пройшли все коло
    }
    return nullptr;
}

void OpenAddressingHashTable::erase(long long key) {
    int index = hash(key);
    int startIndex = index;

    while (table[index].status != EMPTY) {
        if (table[index].status == OCCUPIED && table[index].key == key) {
            table[index].status = DELETED; // "Ліниве" видалення
            count--;
            return;
        }
        index = (index + 1) % M;
        if (index == startIndex) break;
    }
}

int OpenAddressingHashTable::size() const {
    return count;
}