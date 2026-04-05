#include "ChainHashTableDynamic.h"
#include <iostream>

// Виклик конструктора базового класу через список ініціалізації
ChainHashTableDynamic::ChainHashTableDynamic(int initialCapacity)
    : BaseHashTable("Динамічна хеш-таблиця за методом ланцюжків"), M(initialCapacity), count(0) {
    bucketsArray = new LinkedList[M];
}

ChainHashTableDynamic::~ChainHashTableDynamic() {
    delete[] bucketsArray;
}

int ChainHashTableDynamic::hash(long long key) const {
    return static_cast<int>(key % M);
}

void ChainHashTableDynamic::rehash() {
    int oldM = M;
    LinkedList* oldArray = bucketsArray;

    // Збільшуємо розмір вдвічі
    M = oldM * 2;
    bucketsArray = new LinkedList[M];

    // Тимчасово зберігаємо count, бо insert буде його знову інкрементувати
    int currentCount = count;
    count = 0;

    for (int i = 0; i < oldM; ++i) {
        HashNode* current = oldArray[i].getHead();
        while (current != nullptr) {
            // Вставляємо в новий масив за новими хеш-індексами
            insert(current->key, current->value);
            current = current->next;
        }
    }

    delete[] oldArray;
    std::cout << "--- [" << implementationName << "] Rehashed: M = " << M << " ---" << std::endl;
}

void ChainHashTableDynamic::insert(long long key, const University& value) {
    // Автоматичне розширення при перевищенні порогу
    if (getLoadFactor() > maxLoadFactor) {
        rehash();
    }

    int index = hash(key);
    int oldSize = bucketsArray[index].size();
    bucketsArray[index].insertOrUpdate(key, value);

    if (bucketsArray[index].size() > oldSize) {
        count++;
    }
}

University* ChainHashTableDynamic::find(long long key) {
    int index = hash(key);
    HashNode* node = bucketsArray[index].find(key);
    return (node != nullptr) ? &(node->value) : nullptr;
}

void ChainHashTableDynamic::erase(long long key) {
    int index = hash(key);
    if (bucketsArray[index].remove(key)) {
        count--;
    }
}

int ChainHashTableDynamic::size() const {
    return count;
}