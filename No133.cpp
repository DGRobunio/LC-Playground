//
// Created by zhang on 21/1/4.
//
#include "includes.h"

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }

        unordered_map<Node*, Node*> visited;
        queue<Node*> visitQueue;


        visitQueue.push(node);
        visited[node]=new Node(node->val);

        while (!visitQueue.empty()) {
            auto currentNode = visitQueue.front();
            visitQueue.pop();

            for (auto &neighbor : currentNode->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    // 如果没被访问 加入哈希表中
                    visited[neighbor] = new Node(neighbor->val);
                    visitQueue.push(neighbor);
                }
                visited[currentNode]->neighbors.emplace_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};
