//
// Created by zhang on 21/5/20.
//

#include "includes.h"

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordsCount;
        for (auto& word: words) {
            wordsCount[word]++;
        }
        auto compare = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second == b.second? a.first < b.first: a.second > b.second;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)> wordQueue(compare);
        for (auto& item: wordsCount) {
            wordQueue.emplace(item);
            if (wordQueue.size() > k) {
                wordQueue.pop();
            }
        }
        vector<string> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = wordQueue.top().first;
            wordQueue.pop();
        }
        return result;
    }
};