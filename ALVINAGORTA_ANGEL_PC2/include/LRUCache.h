#pragma once

#include <unordered_map>
#include "DLList.h"

class LRUCache : public ods::DLList {
private:
    std::unordered_map<int, Node*> hashMap;
    int capacity;

    void moveToFront(Node* w);

public:
    LRUCache(int capacity);
    ~LRUCache() = default;

    int get(int key);
    void put(int key, int value);
};