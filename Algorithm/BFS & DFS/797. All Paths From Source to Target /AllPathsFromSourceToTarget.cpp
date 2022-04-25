//
//  AllPathsFromSourceToTarget.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/24.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "AllPathsFromSourceToTarget.hpp"

/**
 Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
 
 The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
 
 Input: graph = [[1,2],[3],[3],[]]
 Output: [[0,1,3],[0,2,3]]
 Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 
 Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
 Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 */

void testAllPathsFromSourceToTarget() {
    vector<vector<int>> graph = {
        {1,2},
        {3},
        {3},
        {}
    };
    printVector(Solution().allPathsSourceTarget(graph));
}

vector<vector<int>> result;
int target;
void _allPathsSourceTarget(vector<vector<int>> &graph, int level, vector<int> path) {
    path.push_back(level);
    if (level == target) {
        result.push_back(path);
        return;
    }
    vector<int> nums = graph[level];
    for (int num : nums) {
        _allPathsSourceTarget(graph, num, path);
    }
}

vector<vector<int>> Solution::allPathsSourceTarget(vector<vector<int>> &graph) {
    target = (int)graph.size() - 1;
    _allPathsSourceTarget(graph, 0, {});
    return result;
}
