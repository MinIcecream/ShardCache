#pragma once

struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int val): key{key}, val{val}, prev{nullptr}, next{nullptr} {}
};