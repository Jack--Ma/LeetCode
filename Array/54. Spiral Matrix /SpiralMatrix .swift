//
//  SpiralMatrix .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/5/8.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/spiral-matrix
 
 Given an m x n matrix, return all elements of the matrix in spiral order.
 */

enum Direction {
    case up
    case down
    case left
    case right
    
    func next() -> Direction {
        switch self {
        case .up:
            return .right
        case .down:
            return .left
        case .left:
            return .up
        case .right:
            return .down
        }
    }
}

extension Solution {
    func SpiralMatrix(_ matrix: [[Int]]) -> [Int] {
        guard !matrix.isEmpty else {
            return []
        }
        
        var result = [Int]()
        let height = matrix.count
        let width = matrix[0].count
        // every point's flag ==> "y.x"
        var points: Set = [("0.0")]
        
        // traverse all number, y==row, x==column
        var direction = Direction.right
        var x = 0, y = 0
        for _ in (0..<height*width) {
            result.append(matrix[y][x])
            points.insert("\(y).\(x)")
            // four direction, when touch a edge, turn the direction
            switch direction {
            case .up:
                y-=1
                if y < 0 || points.contains("\(y).\(x)") {
                    direction = direction.next()
                    y+=1;x+=1
                }
            case .down:
                y+=1
                if y >= height || points.contains("\(y).\(x)") {
                    direction = direction.next()
                    y-=1;x-=1
                }
            case .left:
                x-=1
                if x < 0 || points.contains("\(y).\(x)") {
                    direction = direction.next()
                    x+=1;y-=1
                }
            case .right:
                x+=1
                if x >= width || points.contains("\(y).\(x)") {
                    direction = direction.next()
                    x-=1;y+=1
                }
            }
            
        }
        
        return result
    }
}
