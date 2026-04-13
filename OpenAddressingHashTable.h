#ifndef OPENADDRESSINGHASHTABLE_H
#define OPENADDRESSINGHASHTABLE_H

#include "BaseHashTable.h"
#include <vector>

class OpenAddressingHashTable : public BaseHashTable {
private:
    enum SlotStatus { EMPTY, OCCUPIED, DELETED };

    struct Entry {
        long long key;
        University value;
        SlotStatus status;

        Entry() : key(0), status(EMPTY) {}
    };

    Entry* table;
    int M;
    int count;
    const double maxLoadFactor = 0.5; // Для відкритої адресації краще тримати LF низьким

    int hash(long long key) const;
    void rehash();

public:
    OpenAddressingHashTable(int initialCapacity = 10);
    ~OpenAddressingHashTable() override;

    void insert(long long key, const University& value) override;
    University* find(long long key) override;
    void erase(long long key) override;
    int size() const override;
};

#endif