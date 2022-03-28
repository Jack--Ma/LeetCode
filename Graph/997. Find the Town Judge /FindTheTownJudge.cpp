//
//  FindTheTownJudge.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <unordered_set>
#include "FindTheTownJudge.hpp"

/**
 In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
 
 If the town judge exists, then:
    1. The town judge trusts nobody.
    2. Everybody (except for the town judge) trusts the town judge.
    3. There is exactly one person that satisfies properties 1 and 2.
 
 You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

 Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
 
 Input: n = 2, trust = [[1,2]]
 Output: 2
 Input: n = 3, trust = [[1,3],[2,3]]
 Output: 3
 Input: n = 3, trust = [[1,3],[2,3],[3,1]]
 Output: -1
 */

void testFindJudge() {
    vector<vector<int>> trust = {{1,3},{2,3}};
    cout << Solution().findJudge(3, trust) << endl;
}

// other better solution
int _findJudge_better(int n, vector<vector<int>> &trust) {
    // map index mean people number, map value mean this people relationship(trust or trusted) count
    vector<int> map(n+1, 0);
    for (vector<int> relation : trust) {
        // relation first mean this people trust another one, count--
        map[relation[0]]--;
        // relation second mean this people is trusted with another one, count++
        map[relation[1]]++;
    }
    
    for (int i = 1; i < map.size(); i++) {
        int count = map[i];
        // only count equal n-1 case meet the requirements
        // this people don't trust all others people,
        // and is trusted with all others people
        if (count == n - 1) {
            return i;
        }
    }
    return -1;
}

// my solution by use map and set
int Solution::findJudge(int n, vector<vector<int>> &trust) {
    if (trust.empty()) {
        return n == 1 ? 1 : -1;
    }
    // key mean the people be trusted, value mean the number of trusted people
    unordered_map<int, int> judgeMap;
    // store all people which truest other people
    unordered_set<int> notJudgeSet;
    
    for (vector<int> relation : trust) {
        int aPerson = relation[0];
        notJudgeSet.insert(aPerson);
        int bPerson = relation[1];
        judgeMap[bPerson]++;
        
    }
    
    for (pair<int, int> pair : judgeMap) {
        int people = pair.first;
        int count = pair.second;
        // count n-1 mean this people is trusted with all others people in town
        if (count == n - 1) {
            // and this people must not trust other people
            if (notJudgeSet.find(people) == notJudgeSet.end()) {
                return people;
            }
        }
    }
    
    return -1;
}
