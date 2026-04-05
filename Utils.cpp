#include "Utils.h"
#include <random>

long long generateRandLong() {
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
    std::uniform_int_distribution<long long> dis(1000000, 9999999);
    return dis(gen);
}