#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include "University.h"

class HashTable {
private:
    LinkedList* bucketsArray;        // Динамічний масив списків
    int M;                           // Поточний розмір масиву
    int count;                       // Кількість елементів
    const double maxLoadFactor = 0.75; // Поріг розширення (75%)

    int hash(long long key) const;
    void rehash();                   // Метод для збільшення таблиці

public:
    HashTable(int initialCapacity = 10); // Починаємо з малого розміру
    ~HashTable();

    void insert(long long key, const University& value);
    University* find(long long key);
    void erase(long long key);
    int size() const;

    // Метод для обчислення поточного коефіцієнта завантаженості
    double getLoadFactor() const {
        return static_cast<double>(count) / M;
    }
};

#endif