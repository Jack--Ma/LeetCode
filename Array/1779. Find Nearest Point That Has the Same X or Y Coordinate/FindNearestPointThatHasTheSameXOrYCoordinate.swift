//
//  FindNearestPointThatHasTheSameXOrYCoordinate.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/2/23.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate
 
 You are given two integers, x and y, which represent your current location on a Cartesian grid: (x, y). You are also given an array points where each points[i] = [ai, bi] represents that a point exists at (ai, bi). A point is valid if it shares the same x-coordinate or the same y-coordinate as your location.

 Return the index (0-indexed) of the valid point with the smallest Manhattan distance from your current location. If there are multiple, return the valid point with the smallest index. If there are no valid points, return -1.

 The Manhattan distance between two points (x1, y1) and (x2, y2) is abs(x1 - x2) + abs(y1 - y2).
 
 Input: x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
 Output: 2
 Explanation: Of all the points, only [3,1], [2,4] and [4,4] are valid. Of the valid points, [2,4] and [4,4] have the smallest Manhattan distance from your current location, with a distance of 1. [2,4] has the smallest index, so return 2.
 */

extension Solution {
    func FindNearestPointThatHasTheSameXOrYCoordinate(_ x: Int, _ y:Int, _ points: [[Int]]) -> Int {
        var result = -1
        var minDistance = LONG_MAX
        
        for i in (0..<points.count).reversed() {
            let item = points[i]
            if x != item[0] && y != item[1] {
                continue
            }
            if x == item[0] {
                let distance = abs(y-item[1])
                if distance <= minDistance {
                    minDistance = distance
                    result = i
                }
                continue
            }
            if y == item[1] {
                let distance = abs(x-item[0])
                if distance <= minDistance {
                    minDistance = distance
                    result = i
                }
                continue
            }
        }
        
        return result
    }
}
