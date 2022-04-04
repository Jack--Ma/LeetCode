//
//  SortCharactersByFrequency.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/3.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <unordered_map>
#include <queue>
#include "SortCharactersByFrequency.hpp"

/**
 Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

 Return the sorted string. If there are multiple answers, return any of them.

 Input: s = "tree"
 Output: "eert"
 Explanation: 'e' appears twice while 'r' and 't' both appear once.
 So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 */
void testFrequencySort() {
    string s = "Aabb";
    cout << Solution().frequencySort(s) << endl;
}

struct compare {
    bool operator()(pair<char, int>& a, pair<char, int>& b) {
        return a.second < b.second;
    }
};

string Solution::frequencySort(string s) {
    unordered_map<char, int> map;
    for (char sChar : s) {
        map[sChar]++;
    }
    
    priority_queue<pair<char, int>, vector<pair<char, int>>, compare> queue;
    for (auto pair : map) {
        queue.push(pair);
    }
    
    string result;
    while (!queue.empty()) {
        pair<char, int> topPair = queue.top();
        int i = topPair.second;
        while (i-- > 0) {
            result.push_back(topPair.first);
        }
        queue.pop();
    }
    
    return result;
}
