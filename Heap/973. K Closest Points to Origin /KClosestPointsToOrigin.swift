//
//  KClosestPointsToOrigin.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/5/9.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/*
 https://leetcode.com/problems/k-closest-points-to-origin
 
 Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

 The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

 You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
 */

extension Solution {
    func KClosestPointsToOrigin(_ points: [[Int]], _ k: Int) -> [[Int]] {
        let sortedPoints = points.sorted { point1, point2 in
            let distance1 = point1[0]*point1[0]+point1[1]*point1[1]
            let distance2 = point2[0]*point2[0]+point2[1]*point2[1]
            
            return distance1 < distance2
        }
        
        var result = [[Int]]()
        
        var i = 0
        while i < k {
            result.append(sortedPoints[i])
            i+=1
        }
        
        return result
    }
}
