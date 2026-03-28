#include "../include/simple_mutex_cache.h"

SimpleMutexCache::~SimpleMutexCache() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr -> next;
        delete curr;
        curr = next;
    }
}
std::optional<int> SimpleMutexCache::get(int key) {
    std::lock_guard<std::mutex> lock(m); // locks here
    if (!map.count(key)) {
        return {};
    }
    Node* node = map[key];

    removeFromLinkedList(node);
    addToLinkedList(node);
    return node -> val;
}

void SimpleMutexCache::put(int key, int value) {
    std::lock_guard<std::mutex> lock(m); // locks here

    if (map.count(key)) {
        Node* node = map[key];
        node -> val = value;
        removeFromLinkedList(node);
        addToLinkedList(node);
    }
    else {
        if (map.size() == capacity) {
            Node* lruNode = tail -> prev;
            removeFromLinkedList(lruNode);
            map.erase(lruNode -> key);
            delete lruNode;
        }
        Node* newNode = new Node(key, value); 
        addToLinkedList(newNode);
        map[key] = newNode;
    }
}

void SimpleMutexCache::removeFromLinkedList(Node* node) {
    node -> prev -> next = node -> next;
    node -> next -> prev = node -> prev;
}

void SimpleMutexCache::addToLinkedList(Node* node) {
    Node* temp = head -> next;
    head -> next = node;
    node -> prev = head;

    temp -> prev = node;
    node -> next = temp;
}
