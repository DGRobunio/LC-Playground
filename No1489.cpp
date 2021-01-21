//
// Created by zhang on 21/1/21.
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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int edgesSize = edges.size();
        // 记录边的原始顺序
        for (int i = 0; i < edgesSize; i++) {
           edges[i].emplace_back(i);
        }
        // 对边根据权值排序
        sort(edges.begin(), edges.end(), [&](auto x, auto y) { return x[2] < y[2];});

        // 计算最小生成树的权值
        DisjointSetUnion dsuValue(n);
        int value = 0;
        // Kruskal算法求最小生成树
        for (const auto& edge: edges) {
            if (dsuValue.merge(edge[0], edge[1])) {
                value += edge[2];
            }
        }

        vector<vector<int>> result(2);

        for (int i = 0; i < edgesSize; i++) {
            // 判断是否为关键边
            DisjointSetUnion dsu(n);
            int tempValue = 0;
            for (int j = 0; j < edgesSize; j++) {
                if (j != i && dsu.merge(edges[j][0], edges[j][1])) {
                    tempValue += edges[j][2];
                }
            }
            // 当经过Kruskal算法后，不能得到一整个连通图 或者 对应的最小生成树权值大于先前得到的权值，则该边为关键边
            if (dsu.getSetCount() != 1 || (dsu.getSetCount() == 1 && tempValue > value)) {
                // 将该边原始的位置记录
                result[0].emplace_back(edges[i][3]);
                // 由于关键边满足所有伪关键边的条件，在确定其为关键边后，直接开始下一条边的判断
                continue;
            }

            // 判断是否为伪关键边
            dsu = DisjointSetUnion(n);
            // 先将当前边合并
            dsu.merge(edges[i][0], edges[i][1]);
            tempValue = edges[i][2];
            for (int j = 0; j < edgesSize; j++) {
                if (j != i && dsu.merge(edges[j][0], edges[j][1])) {
                    tempValue += edges[j][2];
                }
            }
            // 当经过Kruskal算法后，得到的最小生成树权值与先前一致，则该边为伪关键边
            if (tempValue == value) {
                // 将该边原始的位置记录
                result[1].emplace_back(edges[i][3]);
            }
        }

        return result;

    }
};
