#include <iostream>
#include <random>
#include "University.h"
#include "HashTable.h"

// Функція для генерації випадкового великого числа
long long generateRandLong() {
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
    std::uniform_int_distribution<long long> dis(1000000, 9999999);
    return dis(gen);
}

int main() {
    HashTable table;

    std::cout << "--- Тестування хеш-таблиці ---" << std::endl;

    for (int i = 0; i < 5; ++i) {
        long long key = generateRandLong();
        University uni;
        table.insert(key, uni);
        std::cout << "Додано ключ: " << key << " | ";
        uni.display();
    }

    long long testKey = generateRandLong();
    University testUni;
    table.insert(testKey, testUni);

    std::cout << "\nПошук за ключем " << testKey << "..." << std::endl;
    University* found = table.find(testKey);

    if (found) {
        std::cout << "Знайдено: ";
        found->display();
    } else {
        std::cout << "Елемент не знайдено." << std::endl;
    }

    std::cout << "\nЗагальна кількість елементів: " << table.size() << std::endl;

    std::cout << "Видалення ключа " << testKey << "..." << std::endl;
    table.erase(testKey);
    std::cout << "Новий розмір таблиці: " << table.size() << std::endl;

    return 0;
}