#include "HashTable.h"
#include <iostream>

HashTable::HashTable(int initialCapacity) : M(initialCapacity), count(0) {
    bucketsArray = new LinkedList[M];
}

HashTable::~HashTable() {
    delete[] bucketsArray;
}

int HashTable::hash(long long key) const {
    return static_cast<int>(key % M);
}

void HashTable::rehash() {
    int oldM = M;
    LinkedList* oldArray = bucketsArray;

    // Збільшуємо розмір вдвічі
    M = oldM * 2;
    bucketsArray = new LinkedList[M];
    count = 0; // Скидаємо лічильник, бо insert буде його інкрементувати

    // Переносимо всі елементи зі старої таблиці в нову
    for (int i = 0; i < oldM; ++i) {
        HashNode* current = oldArray[i].getHead();
        while (current != nullptr) {
            insert(current->key, current->value); // insert використає нове M
            current = current->next;
        }
    }

    delete[] oldArray; // Видаляємо стару пам'ять
    std::cout << "--- Рехешування: новий розмір M = " << M << " ---" << std::endl;
}

void HashTable::insert(long long key, const University& value) {
    // Перевірка на завантаженість перед вставкою
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

University* HashTable::find(long long key) {
    int index = hash(key);
    HashNode* node = bucketsArray[index].find(key);
    return (node != nullptr) ? &(node->value) : nullptr;
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