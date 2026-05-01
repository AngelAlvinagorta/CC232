#include "LRUCache.h"
#include <iostream>

void LRUCache::moveToFront(Node* w) {

    w->prev->next = w->next;
    w->next->prev = w->prev;

    Node* temp = dummy.next;
    dummy.next = w;
    w->prev = &dummy;
    w->next = temp;
    temp->prev = w;
}

LRUCache::LRUCache(int capacity) {
    this->capacity = capacity;
}

int LRUCache::get(int key) {
    if (hashMap.find(key) == hashMap.end())
        return -1;

    moveToFront(hashMap[key]);
    return hashMap[key]->value;
}

void LRUCache::put(int key, int value) {
    if (hashMap.find(key) != hashMap.end()) {
        hashMap[key]->value = value;
        moveToFront(hashMap[key]);
    } else {
        if (n == capacity) {
            Node* lru = dummy.prev;   
            hashMap.erase(lru->key);
            removeNode(lru);         
        }
        Node* newNode = addBefore(dummy.next, key, value);
        hashMap[key] = newNode;
    }
}

void LRUCache::printCache() {
    std::cout << "Frente - Mas Reciente ";  
    Node* current = dummy.next;
    while (current != &dummy) {
        std::cout << "(" << current->key << ", " << current->value << ") ";
        current = current->next;
    }
    std::cout << "Final - Menos Reciente\n\n";
}