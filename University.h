#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <vector>

struct University {
    std::string name;
    int studentsCount;
    bool hasTurnstiles;

    // Конструктор, который будет генерировать случайные данные
    University();

    // Вспомогательный метод для вывода (для тестов)
    void display() const;
};

#endif