//
// Created by zhang on 21/1/12.
//

#include "includes.h"

class Solution {
public:
//    拓扑排序（图的入度，图的边，图的端点）
    vector<int> topSort(vector<int>& deg, vector<vector<int>>& graph, vector<int>& items) {
        queue<int> Q;
        for (auto& item: items) {
            if (deg[item] == 0) {
                Q.push(item);
            }
        }
        vector<int> result;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            result.emplace_back(u);
//            遍历u的边指向的端点v
            for (auto& v: graph[u]) {
//                如果v的入度剔除uv边后为0则入队
                if (--deg[v] == 0) {
                    Q.push(v);
                }
            }
        }
        return result.size() == items.size() ? result : vector<int>{};
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> groupItem(n + m);

        // 组间和组内依赖图
        vector<vector<int>> groupGraph(n + m);
        vector<vector<int>> itemGraph(n);

        // 组间和组内入度数组
        vector<int> groupDegree(n + m, 0);
        vector<int> itemDegree(n, 0);

//        给组赋予编码，即端点编号
        vector<int> id;
        for (int i = 0; i < n + m; ++i) {
            id.emplace_back(i);
        }

        int leftId = m;
        // 给未分配的 item 分配一个 groupId
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = leftId++;
            }
            groupItem[group[i]].emplace_back(i);
        }
        // 依赖关系建图
        for (int i = 0; i < n; ++i) {
//            获取每个项目所属的小组id
            int curGroupId = group[i];
//            查找它的前置项目的所属小组id
            for (auto& item: beforeItems[i]) {
                int beforeGroupId = group[item];
//                如果前置项目和当前项目所属同一个小组，则将关系映射的边添加到项目图中，不然添加到小组图中
//                同时增加对应项目/小组的入度
                if (beforeGroupId == curGroupId) {
                    itemDegree[i] += 1;
                    itemGraph[item].emplace_back(i);
                } else {
                    groupDegree[curGroupId] += 1;
                    groupGraph[beforeGroupId].emplace_back(curGroupId);
                }
            }
        }

        // 组间拓扑关系排序
        vector<int> groupTopSort = topSort(groupDegree, groupGraph, id);
        if (groupTopSort.size() == 0) {
            return vector<int>{};
        }
        vector<int> ans;
        // 组内拓扑关系排序
        for (auto& curGroupId: groupTopSort) {
            int size = groupItem[curGroupId].size();
            if (size == 0) {
                continue;
            }
            vector<int> result = topSort(itemDegree, itemGraph, groupItem[curGroupId]);
            if (result.size() == 0) {
                return vector<int>{};
            }
            for (auto& item: result) {
                ans.emplace_back(item);
            }
        }
        return ans;
    }
};
