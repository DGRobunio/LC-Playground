//
// Created by zhang on 21/1/6.
//
#include "includes.h"

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int strNum = 0;
        unordered_map<string, int> chars;
        // 给每个字母赋值
        for (auto& equation: equations) {
            if (chars.find(equation[0]) == chars.end()) {
                chars[equation[0]] = strNum++;
            }
            if (chars.find(equation[1]) == chars.end()) {
                chars[equation[1]] = strNum++;
            }
        }

        // 将已知条件记录到图中
        vector<vector<double>> graph(strNum, vector<double>(strNum, -1));
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            int vectorSource = chars[equations[i][0]];
            int vectorDestination = chars[equations[i][1]];
            graph[vectorSource][vectorDestination] = values[i];
            graph[vectorDestination][vectorSource] = 1.0 / values[i];
        }

        // floyd算法计算每两个端点之间的值
        for (int k = 0; k < strNum; k++) {
            for (int i = 0; i < strNum; i++) {
                for (int j = 0; j < strNum; j++) {
                    if (graph[i][k] > 0 && graph[k][j] > 0) {
                        graph[i][j] = graph[i][k] * graph[k][j];
                    }
                }
            }
        }

        vector<double> results;

        for (auto& q: queries) {
            double result = -1.0;
            if (chars.find(q[0]) != chars.end() && chars.find(q[1]) != chars.end()) {
                int vectorSource = chars[q[0]];
                int vectorDestination = chars[q[1]];
                if (graph[vectorSource][vectorDestination] > 0) {
                    result = graph[vectorSource][vectorDestination];
                }
            }
            results.emplace_back(result);
        }

        return results;
    }
};