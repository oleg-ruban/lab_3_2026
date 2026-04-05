#include "HashTable.h"

HashTable::HashTable() : count(0) {}

int HashTable::hash(long long key) const {
    return static_cast<int>(key % M);
}

void HashTable::insert(long long key, const University& value) {
    int index = hash(key);
    int oldSize = bucketsArray[index].size();

    bucketsArray[index].insertOrUpdate(key, value);

    // Якщо розмір списку збільшився, значить ми додали новий елемент
    if (bucketsArray[index].size() > oldSize) {
        count++;
    }
}

University* HashTable::find(long long key) {
    int index = hash(key);
    HashNode* node = bucketsArray[index].find(key);
    if (node != nullptr) {
        return &(node->value);
    }
    return nullptr;
}

void HashTable::erase(long long key) {
    int index = hash(key);
    if (bucketsArray[index].remove(key)) {
        count--;
    }
}

int HashTable::size() const {
    return count;
}