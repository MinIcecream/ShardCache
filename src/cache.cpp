#include "../include/cache.h"

Cache::~Cache() {
    Node* curr = head;
    while (curr) {
        Node* next = curr -> next;
        delete curr;
        curr = next;
    }
}
std::optional<int> Cache::get(int key) {
    if (!map.count(key)) {
        return {};
    }
    Node* node = map[key];

    removeFromLinkedList(node);
    addToLinkedList(node);
    return node -> val;
}

void Cache::put(int key, int value) {
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

void Cache::removeFromLinkedList(Node* node) {
    node -> prev -> next = node -> next;
    node -> next -> prev = node -> prev;
}

void Cache::addToLinkedList(Node* node) {
    Node* temp = head -> next;
    head -> next = node;
    node -> prev = head;

    temp -> prev = node;
    node -> next = temp;
}
