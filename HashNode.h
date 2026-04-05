#ifndef HASHNODE_H
#define HASHNODE_H

#include "University.h"

// Структура вузла хеш-таблиці
struct HashNode {
    long long key;       // Унікальний ключ-ідентифікатор
    University value;    // Дані про університет
    HashNode* next;      // Покажчик на наступний вузол у ланцюжку

    // Конструктор для створення вузла
    HashNode(long long k, const University& v);
};

#endif