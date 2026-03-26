#pragma once
#include <optional>
#include <iostream>
#include <unordered_map>

struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int val): key{key}, val{val}, prev{nullptr}, next{nullptr} {}
};

class Cache {
    size_t capacity;
    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> map;

    void removeFromLinkedList(Node* node);
    void addToLinkedList(Node* node);

    public:
    ~Cache();
    Cache(size_t capacity): capacity{capacity}, head{new Node(0, 0)}, tail{new Node(0, 0)} {
        if (capacity < 1) {
            throw std::invalid_argument("Capacity must be >0!");
        }
        head -> next = tail;
        tail -> prev = head;
    }
    std::optional<int> get(int key); // optional to account for cache misses
    void put(int key, int value); // assume put never fails
};