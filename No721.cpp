//
// Created by zhang on 21/1/18.
//

#include "includes.h"


class DisjointSetUnion {
private:
    unordered_map<int, int> father, rank;
public:
//    DisjointSetUnion()

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


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int num = accounts.size();
//        记录每个邮箱初始所出现的账号
        unordered_map<string, int> mailFirstAppearAccount;
        DisjointSetUnion dsu;
        for (int i = 0; i < num; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mailFirstAppearAccount.find(accounts[i][j]) == mailFirstAppearAccount.end()) {
                    mailFirstAppearAccount[accounts[i][j]] = i;
                } else {
                    dsu.merge(i, mailFirstAppearAccount[accounts[i][j]]);
                }
            }
        }

//        将所属同一个人的账户合并，并利用set排序
        unordered_map<int, set<string>> record;
        for (int i = 0; i < num; i++) {
            int root = dsu.find(i);
            for (int j = 1; j < accounts[i].size(); j++) {
                record[root].insert(accounts[i][j]);
            }
        }

//        格式化答案
        vector<vector<string>> result;
        for (const auto& it: record) {
            vector<string> user;
            user.emplace_back(accounts[it.first][0]);
            for (const auto& mail: it.second) {
                user.emplace_back(mail);
            }
            result.emplace_back(user);
        }
        return result;
    }
};