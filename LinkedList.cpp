#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), count(0) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::insertOrUpdate(long long key, const University& value) {
    HashNode* current = head;
    
    // 1. Шукаємо, чи є такий ключ
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value; // Замінюємо значення (як за умови завдання)
            return;
        }
        current = current->next;
    }

    // 2. Якщо не знайшли, додаємо новий вузол на початок списку
    HashNode* newNode = new HashNode(key, value);
    newNode->next = head;
    head = newNode;
    count++;
}

HashNode* LinkedList::find(long long key) const {
    HashNode* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

bool LinkedList::remove(long long key) {
    HashNode* current = head;
    HashNode* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            count--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

int LinkedList::size() const {
    return count;
}

void LinkedList::clear() {
    while (head != nullptr) {
        HashNode* temp = head;
        head = head->next;
        delete temp;
    }
    count = 0;
}