//
//  MinimumNumberOfVerticesToReachAllNodes.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MinimumNumberOfVerticesToReachAllNodes.hpp"

/**
 Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.
 
 Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.
 
 Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
 Output: [0,3]
 Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].
 
 Input: n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
 Output: [0,2,3]
 Explanation: Notice that vertices 0, 3 and 2 are not reachable from any other node, so we must include them. Also any of these vertices can reach nodes 1 and 4.
 */

void testFindSmallestSetOfVertices() {
    vector<vector<int>> edges = {{0,1},{2,1},{3,1},{1,4},{2,4}};
    printVector(Solution().findSmallestSetOfVertices(5, edges));
}

vector<int> Solution::findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    // index mean number, value mean whether have node point to this number
    vector<int> reachNodes(n, 0);
    
    // set 1 mean there is a node point to second number
    for (vector<int> edge : edges) {
        int second = edge[1];
        reachNodes[second] = 1;
    }
    
    /**
     Eg. default is 0, if has relationship set 1
       0 1 2 3 4
     0   1
     1         1
     2   1     1
     3   1
     4
     reachNodes contain number 1/4, and the number 0/2/3 are not pointed by other nodes
     so we just need to filter this number
     */
    
    vector<int> result = {};
    for (int i = 0; i < n; i++) {
        if (reachNodes[i] == 0) {
            result.push_back(i);
        }
    }
    
    return result;
}
