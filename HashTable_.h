#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include "University.h"

// Клас Хеш-таблиці з методом ланцюжків
class HashTable {
private:
    static const int M = 10000;      // Розмір масиву бакетів (ячейок)
    LinkedList bucketsArray[M];      // Масив зв’язних списків
    int count;                       // Поточна кількість елементів у таблиці

    // Хеш-функція: залишок від ділення ключа на розмір масиву
    int hash(long long key) const;

public:
    HashTable();

    // Додавання значення за ключем (або заміна, якщо ключ вже існує)
    void insert(long long key, const University& value);

    // Пошук значення за ключем
    University* find(long long key);

    // Видалення елемента за ключем
    void erase(long long key);

    // Повертає загальну кількість елементів у хеш-таблиці
    int size() const;
};

#endif