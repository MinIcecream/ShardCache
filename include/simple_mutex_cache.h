
#pragma once
#include <optional>
#include <iostream>
#include <unordered_map>
#include "node.h"
#include "cache.h"
#include <mutex>

class SimpleMutexCache: public Cache{
    size_t capacity;
    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> map;
    std::mutex m;

    void removeFromLinkedList(Node* node);
    void addToLinkedList(Node* node);

    public:
    ~SimpleMutexCache();
    SimpleMutexCache(size_t capacity): capacity{capacity}, head{new Node(0, 0)}, tail{new Node(0, 0)} {
        if (capacity < 1) {
            throw std::invalid_argument("Capacity must be >0!");
        }
        head -> next = tail;
        tail -> prev = head;
    }
    std::optional<int> get(int key) override; // optional to account for cache misses
    void put(int key, int value) override; // assume put never fails
};