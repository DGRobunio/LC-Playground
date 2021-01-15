//
// Created by zhang on 21/1/15.
//

#include "includes.h"

/*
 * 把石头的坐标，想象成以直线X=k或Y=k为端点的图中，两端点之间的的边即可
 * 石头：[1,2]
 * 转换成：
 * （X=1）-------------------（Y=2）
 *         ↑这条边，记为[1,2]
 * */

class Solution {
private:
    unordered_map<int, int> father, rank;
public:
    int find (int x) {
        if (!father.count(x)) {
            father[x] = x;
            rank[x] = 1;
        }
        return father[x] == x ? x :father[x] = find(father[x]);
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

    int numberOfFather () {
        int num = 0;
        for (auto& [x, fa]: father) {
            if (x == fa) {
                num++;
            }
        }
        return num;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for (auto& stone: stones) {
//            根据X,Y的范围，通过给Y增加10001的形式将x和y的直线记录在同一个图中
            merge(stone[0], stone[1]+10001);
        }
        return n - numberOfFather();
    }
};