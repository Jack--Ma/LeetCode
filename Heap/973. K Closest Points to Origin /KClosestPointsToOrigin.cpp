//
//  KClosestPointsToOrigin.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/4.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include <unordered_map>
#include "KClosestPointsToOrigin.hpp"

/**
 Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

 The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
 
 Input: points = [[1,3],[-2,2]], k = 1
 Output: [[-2,2]]
 
 Input: points = [[3,3],[5,-1],[-2,4]], k = 2
 Output: [[3,3],[-2,4]]
 */

void testKClosest() {
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    points = {{1,3},{-2,2},{2,-2}};
    printVector(Solution().kClosest(points, 2));
}

// solution by use vector sort
vector<vector<int>> _kClosest_vector(vector<vector<int>>& points, int k) {
    sort(points.begin(), points.end(), [](vector<int>& point1, vector<int>& point2){
        int distance1 = point1[0]*point1[0] + point1[1]*point1[1];
        int distance2 = point2[0]*point2[0] + point2[1]*point2[1];
        return distance1 < distance2;
    });
    
    vector<vector<int>> result;
    for (int i = 0; i < k; i++) {
        result.push_back(points[i]);
    }
    return result;
}

struct compare {
    bool operator()(pair<int, vector<vector<int>>>& a, pair<int, vector<vector<int>>>& b) {
        return a.first < b.first;
    }
};

// solution by use priority queue
vector<vector<int>> Solution::kClosest(vector<vector<int>>& points, int k) {
    // 1. build map, key is the distance, value is point array
    unordered_map<int, vector<vector<int>>> map;
    for (vector<int> point : points) {
        int distance = point[0]*point[0] + point[1]*point[1];
        map[distance].push_back(point);
    }
    
    // 2. build priority queue, in distance longer order
    priority_queue<pair<int, vector<vector<int>>>, vector<pair<int, vector<vector<int>>>>, compare> queue;
    int kNum = 0;
    for (pair<int, vector<vector<int>>> pair : map) {
        queue.push(pair);
        kNum += pair.second.size();
        if (kNum > k) {
            queue.pop();
        }
    }
    
    // 3. build result array
    vector<vector<int>> result;
    while (!queue.empty()) {
        vector<vector<int>> correctPoints = queue.top().second;
        result.insert(result.end(), correctPoints.begin(), correctPoints.end());
        queue.pop();
    }
    
    return result;
}
