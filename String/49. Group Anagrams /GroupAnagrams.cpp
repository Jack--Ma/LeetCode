//
//  GroupAnagrams.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/14.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "GroupAnagrams.hpp"

/**
 Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 Input: strs = ["eat","tea","tan","ate","nat","bat"]
 Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 */

void testGroupAnagrams() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    printVector(Solution().groupAnagrams(strs));
}

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    
    unordered_map<string, vector<string>> strMap;
    
    for (string str : strs) {
        string sortStr = str;
        sort(sortStr.begin(), sortStr.end());
        if (strMap.find(sortStr) == strMap.end()) {
            // not find
            vector<string> strList;
            strList.push_back(str);
            strMap[sortStr] = strList;
        } else {
            vector<string> strList = strMap[sortStr];
            strList.push_back(str);
            strMap[sortStr] = strList;
        }
    }
    
    for (auto s : strMap) {
        result.push_back(s.second);
    }
    
    return result;
}
