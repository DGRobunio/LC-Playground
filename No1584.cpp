//
// Created by zhang on 21/1/19.
//

#include "includes.h"

class DisjointSetUnion {
private:
    vector<int> father, rank;
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
    bool merge(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
        if (rank[rootX] <= rank[rootY]) {
            father[rootX] = rootY;
        } else {
            father[rootY] = rootX;
        }
        if (rank[rootX] == rank[rootY] && rootX != rootY) {
            rank[rootY]++;
        }
        return true;
    }
};

struct Edge {
        int len, x, y;
        Edge(int len, int x, int y) : len(len), x(x), y(y) {
        }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int pointNum = points.size();
        DisjointSetUnion dsu(pointNum);

//        害搁这儿用map偷懒呢？直接适得其反呀
//        map<int, vector<int>> manhattanDistanceMap;
//        for (int i = 0; i < pointNum - 1; i++) {
//            for (int j = i + 1; j < pointNum; j++) {
//                int mDistance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
//                if (manhattanDistanceMap.count(mDistance)) {
//                    manhattanDistanceMap[mDistance].emplace_back(i);
//                    manhattanDistanceMap[mDistance].emplace_back(j);
//                } else {
//                    vector<int> log;
//                    log.emplace_back(i);
//                    log.emplace_back(j);
//                    manhattanDistanceMap[mDistance] = log;
//                }
//            }
//        }
//        int result = 0;
//        for (const auto& manhattanDistance: manhattanDistanceMap) {
//            int vecSize = manhattanDistance.second.size();
//            for (int i = 0; i < vecSize; i+=2) {
//                if (dsu.find(manhattanDistance.second[i]) != dsu.find(manhattanDistance.second[i+1])) {
//                    dsu.merge(manhattanDistance.second[i], manhattanDistance.second[i+1]);
//                    result += manhattanDistance.first;
//                }
//            }
//        }

        auto dist = [&](int x, int y) -> int {
            return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
        };
        vector<Edge> edges;
        for (int i = 0; i < pointNum; i++) {
            for (int j = i + 1; j < pointNum; j++) {
                edges.emplace_back(dist(i, j), i, j);
            }
        }
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) -> int { return a.len < b.len; });

        int result = 0, mergedPoints = 1;
        for (const auto& [len, x, y]: edges) {
            if (dsu.merge(x, y)) {
                result += len;
                mergedPoints++;
                if (mergedPoints == pointNum) {
                    break;
                }
            }
        }

        return result;
    }
};