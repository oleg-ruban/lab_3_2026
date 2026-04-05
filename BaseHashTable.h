#ifndef BASEHASHTABLE_H
#define BASEHASHTABLE_H

#include <string>
#include "University.h"

class BaseHashTable {
protected:
    std::string implementationName; // Поле для зберігання назви реалізації

public:
    // Конструктор приймає назву і записує її в поле
    BaseHashTable(const std::string& name) : implementationName(name) {}

    virtual ~BaseHashTable() {}

    // Метод для отримання назви (геттер)
    std::string getImplementationName() const {
        return implementationName;
    }

    // Віртуальні методи
    virtual void insert(long long key, const University& value) = 0;
    virtual University* find(long long key) = 0;
    virtual void erase(long long key) = 0;
    virtual int size() const = 0;
};

#endif