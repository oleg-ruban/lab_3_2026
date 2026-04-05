#include <iostream>
#include <unordered_map>
#include <ctime>
#include "Testing.h"
#include "BaseHashTable.h"
#include "Utils.h"

using namespace std;

bool testHashTable(BaseHashTable* hashTable) {
    cout << "Запуск тесту для: " << hashTable->getImplementationName() << endl;

    const int iters = 500000;
    const int keysAmount = iters * 1;

    // 1. Генерація випадкових ключів
    long long* keys = new long long[keysAmount];
    long long* keysToInsert = new long long[iters];
    long long* keysToErase = new long long[iters];
    long long* keysToFind = new long long[iters];

    for (int i = 0; i < keysAmount; i++) {
        keys[i] = generateRandLong();
    }

    for (int i = 0; i < iters; i++) {
        keysToInsert[i] = keys[generateRandLong() % keysAmount];
        keysToErase[i] = keys[generateRandLong() % keysAmount];
        keysToFind[i] = keys[generateRandLong() % keysAmount];
    }

    // 2. Тестування ВЛАСНОЇ HashTable
    clock_t myStart = clock();

    for (int i = 0; i < iters; i++) {
        hashTable->insert(keysToInsert[i], University()); // Використовуємо University
    }
    int myInsertSize = hashTable->size();

    for (int i = 0; i < iters; i++) {
        hashTable->erase(keysToErase[i]);
    }
    int myEraseSize = hashTable->size();

    int myFoundAmount = 0;
    for (int i = 0; i < iters; i++) {
        if (hashTable->find(keysToFind[i]) != nullptr) {
            myFoundAmount++;
        }
    }
    clock_t myEnd = clock();
    float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;

    // 3. Тестування STL unordered_map (для порівняння)
    unordered_map<long long, University> stlMap;
    clock_t stlStart = clock();

    for (int i = 0; i < iters; i++) {
        stlMap[keysToInsert[i]] = University();
    }
    int stlInsertSize = stlMap.size();

    for (int i = 0; i < iters; i++) {
        stlMap.erase(keysToErase[i]);
    }
    int stlEraseSize = stlMap.size();

    int stlFoundAmount = 0;
    for (int i = 0; i < iters; i++) {
        if (stlMap.find(keysToFind[i]) != stlMap.end()) {
            stlFoundAmount++;
        }
    }
    clock_t stlEnd = clock();
    float stlTime = (float(stlEnd - stlStart)) / CLOCKS_PER_SEC;

    // 4. Виведення результатів
    cout << "--- Результати порівняння ---" << endl;
    cout << "Результати для тесту: " << hashTable->getImplementationName() << ":" << endl;
    cout << "Time: " << myTime << "s, size after insert: " << myInsertSize 
         << ", after erase: " << myEraseSize << ", found: " << myFoundAmount << endl;

    cout << "\nSTL unordered_map:" << endl;
    cout << "Time: " << stlTime << "s, size after insert: " << stlInsertSize 
         << ", after erase: " << stlEraseSize << ", found: " << stlFoundAmount << endl << endl;

    // Очищення пам'яті
    delete[] keys;
    delete[] keysToInsert;
    delete[] keysToErase;
    delete[] keysToFind;

    // Перевірка коректності: результати мають співпадати
    if (myInsertSize == stlInsertSize && myEraseSize == stlEraseSize && myFoundAmount == stlFoundAmount) {
        cout << "SUCCESS: The lab is completed!" << endl;
        return true;
    }

    cerr << "FAILURE: Results do not match STL!" << endl;
    return false;
}