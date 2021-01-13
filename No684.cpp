//
// Created by zhang on 21/1/13.
//
#include "includes.h"

class Solution {
public:
    int find(vector<int>& father, int x) {
        if(father[x] == x) {
            return x;
        } else {
            father[x] = find(father, father[x]);
            return father[x];
        }
    }

    void merge(vector<int>& father, vector<int>& rank, int x, int y) {
        int rootX = find(father, x), rootY = find(father, y);
        if (rank[rootX] <= rank[rootY]) {
            father[rootX] = rootY;
        } else {
            father[rootY] = rootX;
        }
        if (rank[rootX] == rank[rootY] && rootX != rootY) {
            rank[rootY]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int num = edges.size()+1;
        vector<int> father(num);
        vector<int> rank(num,1);
        for (int i = 0; i < num; i++) {
            father[i] = i;
        }

        for (auto& pair: edges) {
            if (find(father, pair[0]) != find(father, pair[1])) {
                merge(father, rank, pair[0], pair[1]);
            } else {
                return pair;
            }
        }
        return vector<int>{};
    }
};
