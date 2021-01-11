//
// Created by zhang on 21/1/11.
//

#include "includes.h"

//并查集
class DisjointSetUnion {
private:
//    存储父节点的集合
    vector<int> father;
//    存储秩的集合
    vector<int> rank;
public:
//    构造函数
    DisjointSetUnion(int n) {
//        初始化集合里元素的个数
        father.resize(n);
        rank.resize(n,1);
//        初始化father集合指向各自自己
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
//            当x所在的集合秩小于等于y时，将x的父节点设置为y，此时新的集合秩不变
            father[rootX] = rootY;
        } else {
//            反之亦然
            father[rootY] = rootX;
        }
//        当两个根节点节点的秩相同时但本身不相同时，合并需要将新的根节点的秩增加1
        if (rank[rootX] == rank[rootY] && rootX != rootY) {
            rank[rootY]++;
        }
    }

};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
//        根据s的长度初始化一个并查集
        DisjointSetUnion dsu(s.length());
//        根据pairs条件，合并集
        for (auto& item: pairs) {
            dsu.merge(item[0], item[1]);
        }
//        定义一个哈希表装载各个集合
        unordered_map<int, vector<int>> setMap;
//        根据dsu装载集合
        for (int i = 0; i < s.length(); i++) {
            setMap[dsu.find(i)].emplace_back(s[i]);
        }
//        对集合内的字母从大到小排序
        for (auto& [num, vec]: setMap) {
            sort(vec.begin(), vec.end(), greater<int>());
        }
//        对字符串s进行重组
        for (int i = 0; i < s.length(); i++) {
//            找到当前字符所在组的根节点
            int root = dsu.find(i);
//            将所在组最小的数字（字符）赋予s[i]
            s[i] = setMap[root].back();
//            pop
            setMap[root].pop_back();
        }

        return s;
    }
};