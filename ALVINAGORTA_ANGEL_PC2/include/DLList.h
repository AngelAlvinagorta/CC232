// Basado en DLList.h usado en clase, sin el uso de templates
#pragma once

#include <cassert>

namespace ods {

class DLList {
protected:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
    };

    Node dummy;
    int n;

    Node* addBefore(Node* w, int key, int value) {
        Node* u = new Node{key, value, w->prev, w};
        u->prev->next = u;
        u->next->prev = u;
        ++n;
        return u;
    }

    void removeNode(Node* w) {
        w->prev->next = w->next;
        w->next->prev = w->prev;
        delete w;
        --n;
    }

public:
    DLList() : n(0) {
        dummy.next = &dummy;
        dummy.prev = &dummy;
    }

    ~DLList() {
        clear();
    }

    // LRUCache no necesita copiar el cache
    DLList(const DLList&) = delete;
    DLList& operator=(const DLList&) = delete;
    DLList(DLList&&) = delete;
    DLList& operator=(DLList&&) = delete;

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    void clear() {
        Node* u = dummy.next;
        while (u != &dummy) {
            Node* w = u->next;
            delete u;
            u = w;
        }
        dummy.next = &dummy;
        dummy.prev = &dummy;
        n = 0;
    }
};

} // namespace ods