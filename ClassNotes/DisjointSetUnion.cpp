//
// Created by zhang on 21/1/18.
//

#include "../includes.h"

//使用vector的并查集实现
class DisjointSetUnionWithVector {
private:
    vector<int> father;
    vector<int> rank;
public:
//    构造函数
    DisjointSetUnion(int n) {
        father.resize(n);
        rank.resize(n,1);
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }
//    查询
    int find(int x) {
        if (father[x] == x) {
            return x;
        } else {
//            路径压缩，每个节点将各自的父节点指向根节点
            father[x] = find(father[x]);
            return father[x];
        }
    }
//    按秩合并
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

//使用哈希表的并查集实现
class DisjointSetUnionWithHashMap {
private:
    unordered_map<int, int> father, rank;
public:
    int find (int x) {
        if (!father.count(x)) {
            father[x] = x;
            rank[x] = 1;
        }
        return father[x] == x? x : father[x] = find(father[x]);
    }
    void merge (int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        father[fy] = fx;
    }
};