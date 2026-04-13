#include <iostream>
#include <vector>
#include "Testing.h"
#include "ChainHashTableStat.h"
#include "ChainHashTableDynamic.h"
#include "MultiplicationHashTable.h"
#include "XorShiftHashTable.h"
#include "OpenAddressingHashTable.h"

using namespace std;

int main() {
    // 1. Налаштування кодування для коректного виводу кирилиці (Windows)
    // system("chcp 65001");

    // 2. Створюємо екземпляри всіх наших реалізацій
    ChainHashTableStat staticChain;
    ChainHashTableDynamic dynamicChain;
    MultiplicationHashTable staticMultiplication;
    XorShiftHashTable staticXor;
    OpenAddressingHashTable openAddressing;

    // 3. Збираємо їх у вектор вказівників на базовий клас
    // Це і є поліморфізм у дії: ми працюємо з різними об'єктами через спільний інтерфейс
    vector<BaseHashTable*> implementations = {
        &staticChain, &dynamicChain, &staticMultiplication, &staticXor, &openAddressing
    };

    cout << "==========================================" << endl;
    cout << "   ЗАПУСК ТЕСТУВАННЯ ХЕШ-ТАБЛИЦЬ     " << endl;
    cout << "==========================================" << endl;

    int successCount = 0;

    // 4. Проходимо циклом по всіх реалізаціях
    for (BaseHashTable* table : implementations) {
        // Ми використовуємо getImplementationName(), який додали в BaseHashTable
        cout << "\n>>> Тестуємо імплементацію: " << table->getImplementationName() << endl;

        if (testHashTable(table)) {
            cout << "[OK] " << table->getImplementationName() << " пройшла всі тести." << endl;
            successCount++;
        } else {
            cerr << "[FAIL] " << table->getImplementationName() << " має помилки!" << endl;
        }
        cout << "------------------------------------------" << endl;
    }

    // 5. Підсумковий звіт
    cout << "\nРЕЗУЛЬТАТ: Успішно протестовано " << successCount
         << " з " << implementations.size() << " реалізацій." << endl;

    if (successCount == implementations.size()) {
        cout << "Всі лабораторні завдання виконано успішно! 🎉" << endl;
    }

    return 0;
}