#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "University.h"

// Структура вузла хеш-таблиці
struct HashNode {
    long long key;       // Унікальний ключ-ідентифікатор
    University value;    // Дані про університет
    HashNode* next;      // Покажчик на наступний вузол у ланцюжку

    // Конструктор для зручного створення вузла
    HashNode(long long k, const University& v) 
        : key(k), value(v), next(nullptr) {}
};

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