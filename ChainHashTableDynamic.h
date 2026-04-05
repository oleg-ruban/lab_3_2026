#ifndef CHAINHASHTABLEDYNAMIC_H
#define CHAINHASHTABLEDYNAMIC_H

#include "BaseHashTable.h"
#include "LinkedList.h"

class ChainHashTableDynamic : public BaseHashTable {
private:
    LinkedList* bucketsArray;        // Динамічний масив списків
    int M;                           // Поточний розмір масиву
    int count;                       // Кількість елементів
    const double maxLoadFactor = 0.75;

    int hash(long long key) const;
    void rehash();

public:
    // Конструктор тепер ініціалізує назву в BaseHashTable
    ChainHashTableDynamic(int initialCapacity = 10);
    ~ChainHashTableDynamic() override;

    // Методи інтерфейсу
    void insert(long long key, const University& value) override;
    University* find(long long key) override;
    void erase(long long key) override;
    int size() const override;

    // Допоміжний метод для Load Factor
    double getLoadFactor() const {
        return static_cast<double>(count) / M;
    }
};

#endif