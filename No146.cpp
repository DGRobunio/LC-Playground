//
// Created by zhang on 21/5/6.
//

#include "includes.h"

class DLinkedNode {
public:
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode *head = new DLinkedNode();
    DLinkedNode *tail = new DLinkedNode();
    int size, capacity;

public:
    LRUCache(int capacity): capacity(capacity), size(0) {
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            DLinkedNode *node = cache[key];
            moveNodeToHead(node);
            return node->value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            DLinkedNode *node = new DLinkedNode(key,value);
            cache[key] = node;
            addNodeToHead(node);
            size++;
            if (size > capacity) {
                DLinkedNode *removed = removeTailNode();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        } else {
            DLinkedNode *node = cache[key];
            node->value = value;
            moveNodeToHead(node);
        }
    }

    void removeNode(DLinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToHead(DLinkedNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void moveNodeToHead(DLinkedNode *node) {
        removeNode(node);
        addNodeToHead(node);
    }

    DLinkedNode* removeTailNode() {
        DLinkedNode *tempNode = tail->prev;
        removeNode(tempNode);
        return tempNode;
    }

};