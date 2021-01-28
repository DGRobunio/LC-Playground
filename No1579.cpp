//
// Created by zhang on 21/1/28.
//

#include "includes.h"

class DisjointSetUnion {
private:
    // 父节点
    vector<int> father;
    // 连通分量大小（节点数）
    vector<int> size;
    // 总数
    int n;
    // 当前连通分量数目
    int setCount;

public:

    DisjointSetUnion(int _n) : n(_n), setCount(_n), father(_n), size(_n, 1) {
//        iota(father.begin(), father.end(), 0);
        for (int i = 0; i < _n; i++) {
            father[i] = i;
        }
    }

    int find(int x) {
        return father[x] == x? x: father[x] = find(father[x]);
    }

    bool merge (int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return false;
        }
        if (size[fx] < size[fy]) {
            swap(fx, fy);
        }

        father[fy] = fx;
        size[fx] += size[fy];
        setCount--;
        return true;
    }

    // 判断两个节点是否连通
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    // 获取连通分量数目
    int getSetCount() {
        return setCount;
    }

};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSetUnion dsuA(n), dsuB(n);
        int result = 0;
        // 节点编号改为从 0 开始
        for (auto& edge: edges) {
            edge[1]--;
            edge[2]--;
        }

        // 公共边
        for (const auto& edge: edges) {
            if (edge[0] == 3) {
                if (dsuA.merge(edge[1],edge[2])) {
                    dsuB.merge(edge[1],edge[2]);
                } else {
                    result++;
                }
            }
        }

        // 独占边
        for (const auto& edge: edges) {
            if (edge[0] == 1) {
                if (!dsuA.merge(edge[1],edge[2])) {
                    result++;
                }
            }
            if (edge[0] == 2) {
                if (!dsuB.merge(edge[1],edge[2])) {
                    result++;
                }
            }
        }

        if (dsuA.getSetCount() != 1 || dsuB.getSetCount() != 1) {
            result = -1;
        }

        return result;
    }
};