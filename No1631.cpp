//
// Created by zhang on 21/1/29.
//
#include "includes.h"

class DisjointSetUnion {
private:
    vector<int> father;

public:
    DisjointSetUnion(int n) {
        father.resize(n);
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    int find(int x) {
        return father[x] == x? x: (father[x] = find(father[x]));
    }

    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        father[fy] = fx;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int result = 0;
//        vector<vector<int>> edges;
        vector<tuple<int, int, int>> edges;
        int row = heights.size();
        int col = heights[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i < row - 1) {
//                    vector<int> edge = { col * i + j, col * (i + 1) +  j , abs(heights[i][j] - heights[i+1][j]) };
//                    edges.emplace_back(edge);
                    edges.emplace_back({ col * i + j, col * (i + 1) +  j , abs(heights[i][j] - heights[i+1][j]) });
                }
                if (j < col - 1) {
//                    vector<int> edge = {col * i +  j, col * i +  (j + 1) , abs(heights[i][j] - heights[i][j+1]) };
//                    edges.emplace_back(edge);
                    edges.emplace_back({col * i +  j, col * i +  (j + 1) , abs(heights[i][j] - heights[i][j+1])});
                }
            }
        }

//        sort(edges.begin(), edges.end(), [&](auto x, auto y) { return x[2] < y[2];});
        sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2) {
            auto&& [x1, y1, v1] = e1;
            auto&& [x2, y2, v2] = e2;
            return v1 < v2;
        });



        DisjointSetUnion dsu(row * col);
        for (const auto& edge: edges) {
            if (dsu.find(0) == dsu.find(row * col -1)) {
                break;
            }
            if (dsu.find(edge[0]) != dsu.find(edge[1])) {
                dsu.merge(edge[0], edge[1]);
                result = max(result, edge[2]);
            }
        }

        return result;
    }
};
