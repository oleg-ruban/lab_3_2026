#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <vector>

struct University {
    std::string name;
    int studentsCount;
    bool hasTurnstiles;

    // Конструктор, який генеруватиме випадкові дані
    University();

    // Допоміжний метод для виведення (для тестів)
    void display() const;
};

#endif