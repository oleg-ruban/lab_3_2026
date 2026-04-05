#include "ChainHashTableStat.h"

ChainHashTableStat::ChainHashTableStat()
    : BaseHashTable("Статична хеш-таблиця за методом ланцюжків"), count(0) {
    // тіло конструктора
}
int ChainHashTableStat::hash(long long key) const {
    return static_cast<int>(key % M);
}

void ChainHashTableStat::insert(long long key, const University& value) {
    int index = hash(key);
    int oldSize = bucketsArray[index].size();

    bucketsArray[index].insertOrUpdate(key, value);

    // Якщо розмір списку збільшився, значить ми додали новий елемент
    if (bucketsArray[index].size() > oldSize) {
        count++;
    }
}

University* ChainHashTableStat::find(long long key) {
    int index = hash(key);
    HashNode* node = bucketsArray[index].find(key);
    if (node != nullptr) {
        return &(node->value);
    }
    return nullptr;
}

void ChainHashTableStat::erase(long long key) {
    int index = hash(key);
    if (bucketsArray[index].remove(key)) {
        count--;
    }
}

int ChainHashTableStat::size() const {
    return count;
}