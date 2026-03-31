#include "University.h"
#include <random>
#include <iostream>

University::University() {
    // Використовуємо статичний генератор, щоб він ініціалізувався один раз
    static std::random_device rd;
    static std::mt19937 gen(rd());

    // 1. Генеруємо назву зі списку пресетів
    static const std::vector<std::string> names = {
        "KPI", "KNU", "KhPI", "Lviv Polytechnic", "NaUKMA", 
        "Oxford", "MIT", "Stanford", "Cambridge", "Harvard"
    };
    
    std::uniform_int_distribution<> nameDist(0, names.size() - 1);
    this->name = names[nameDist(gen)];

    // 2. Генеруємо кількість студентів (від 1000 до 30000)
    std::uniform_int_distribution<> studentDist(1000, 30000);
    this->studentsCount = studentDist(gen);

    // 3. Генеруємо наявність турнікетів (true/false)
    std::uniform_int_distribution<> boolDist(0, 1);
    this->hasTurnstiles = boolDist(gen) == 1;
}

void University::display() const {
    std::cout << "University: " << name 
              << " | Students: " << studentsCount 
              << " | Turnstiles: " << (hasTurnstiles ? "Yes" : "No") << std::endl;
}