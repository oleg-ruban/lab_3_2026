#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "HashNode.h" // Підключаємо винесений вузол

// Клас пов'язаного списку для вирішення колізій
class LinkedList {
private:
    HashNode* head;      // Голова списку
    int count;           // Кількість елементів у конкретному списку

public:
    LinkedList();
    ~LinkedList();

    // Основні методи для роботи хеш-таблиці
    void insertOrUpdate(long long key, const University& value);
    HashNode* find(long long key) const;
    bool remove(long long key);
    
    // Допоміжні методи
    int size() const;
    void clear();
    HashNode* getHead() const { return head; }
};

#endif