#include <iostream>
#include <random>
#include "University.h"
#include "LinkedList.h"

// Функція для генерації випадкового великого числа (long long)
// Використовується як унікальний ключ-ідентифікатор
long long generateRandLong() {
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
    // Діапазон для 7-значних чисел (можна змінити на більший)
    std::uniform_int_distribution<long long> dis(1000000, 9999999);
    return dis(gen);
}

// Клас Хеш-таблиці з методом ланцюжків
class HashTable {
private:
    static const int M = 10000;      // Розмір масиву бакетів (ячейок)
    LinkedList bucketsArray[M];      // Масив зв’язних списків
    int count;                       // Поточна кількість елементів у таблиці

    // Хеш-функція: залишок від ділення ключа на розмір масиву
    int hash(long long key) const {
        return static_cast<int>(key % M);
    }

public:
    HashTable() : count(0) {}

    // Додавання значення за ключем (або заміна, якщо ключ вже існує)
    void insert(long long key, const University& value) {
        int index = hash(key);
        int oldSize = bucketsArray[index].size();

        bucketsArray[index].insertOrUpdate(key, value);

        // Якщо розмір списку збільшився, значить ми додали новий елемент
        if (bucketsArray[index].size() > oldSize) {
            count++;
        }
    }

    // Пошук значення за ключем
    // Повертає вказівник на об'єкт University або nullptr, якщо не знайдено
    University* find(long long key) {
        int index = hash(key);
        HashNode* node = bucketsArray[index].find(key);
        if (node != nullptr) {
            return &(node->value);
        }
        return nullptr;
    }

    // Видалення елемента за ключем
    void erase(long long key) {
        int index = hash(key);
        if (bucketsArray[index].remove(key)) {
            count--;
        }
    }

    // Повертає загальну кількість елементів у хеш-таблиці
    int size() const {
        return count;
    }
};

int main() {
    // Встановлення кодування для коректного відображення символів (опціонально для Windows)
    // setlocale(LC_ALL, "Ukrainian");

    HashTable table;

    std::cout << "--- Тестування хеш-таблиці ---" << std::endl;

    // 1. Генерація та вставка декількох випадкових елементів
    for (int i = 0; i < 5; ++i) {
        long long key = generateRandLong();
        University uni; // Викликається конструктор зі згенерованими даними
        table.insert(key, uni);

        std::cout << "Додано ключ: " << key << " | ";
        uni.display();
    }

    // 2. Демонстрація пошуку
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

    // 3. Виведення загального розміру
    std::cout << "\nЗагальна кількість елементів у таблиці: " << table.size() << std::endl;

    // 4. Демонстрація видалення
    std::cout << "Видалення ключа " << testKey << "..." << std::endl;
    table.erase(testKey);
    std::cout << "Новий розмір таблиці: " << table.size() << std::endl;

    return 0;
}