#include <iostream>
using namespace std;
#include "Testing.h"
#include "ChainHashTableStat.h"

int main() {
    ChainHashTableStat сhainHashTableStat;
    if (testHashTable(&сhainHashTableStat)) {
        cout << "Все тести пройдено успішно!" << endl;
    }
    return 0;
}