//
// Created by zhang on 21/1/25.
//
#include "includes.h"

class DisjointSetUnion {
private:
    vector<int> father;
    vector<int> rank;
public:
    DisjointSetUnion(int n) {
        father.resize(n);
        rank.resize(n,1);
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }
    int find(int x) {
        if (father[x] == x) {
            return x;
        } else {
            father[x] = find(father[x]);
            return father[x];
        }
    }
    void merge(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rank[rootX] <= rank[rootY]) {
            father[rootX] = rootY;
        } else {
            father[rootY] = rootX;
        }
        if (rank[rootX] == rank[rootY] && rootX != rootY) {
            rank[rootY]++;
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int wide = grid.size();
        DisjointSetUnion dsu(wide * 2 * wide * 2);
        for (int i = 0; i < wide; i++) {
            for (int j = 0; j < wide; j++) {
                int index = i * wide + j;
                if (i < wide - 1) {
                    int bottomIndex = (i + 1) * wide + j;
                    dsu.merge(index * 4 + 3, bottomIndex * 4);
                }
                if (j < wide -1) {
                    int rightIndex = index + 1;
                    dsu.merge(index * 4 + 2, rightIndex * 4 + 1);
                }
                if (grid[i][j] == '/') {
                    dsu.merge(index * 4, index * 4 + 1);
                    dsu.merge(index * 4 + 2, index * 4 + 3);
                } else if (grid[i][j] == '\\') {
                    dsu.merge(index * 4, index * 4 + 2);
                    dsu.merge(index * 4 + 1, index * 4 + 3);
                } else {
                    dsu.merge(index * 4, index * 4 + 1);
                    dsu.merge(index * 4 + 1, index * 4 + 2);
                    dsu.merge(index * 4 + 2, index * 4 + 3);
                }
            }
        }

        unordered_set<int> fathers;
        for (int i = 0; i < wide * 2 * wide * 2; i++) {
            fathers.insert(dsu.find(i));
        }

        return fathers.size();
    }
};
