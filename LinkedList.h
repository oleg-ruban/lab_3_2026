#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "University.h"

// Структура вузла хеш-таблиці
struct HashNode {
    long long key;       // Уникальный ключ-идентификатор
    University value;    // Данные об университете
    HashNode* next;      // Указатель на следующий узел в цепочке

    // Конструктор для удобного создания узла
    HashNode(long long k, const University& v) 
        : key(k), value(v), next(nullptr) {}
};

// Класс связанного списка для разрешения коллизий
class LinkedList {
private:
    HashNode* head;      // Голова списка
    int count;           // Количество элементов в конкретном списке

public:
    LinkedList();
    ~LinkedList();

    // Основные методы для работы хеш-таблицы
    void insertOrUpdate(long long key, const University& value);
    HashNode* find(long long key) const;
    bool remove(long long key);
    
    // Вспомогательные методы
    int size() const;
    void clear();
    HashNode* getHead() const { return head; }
};

#endif