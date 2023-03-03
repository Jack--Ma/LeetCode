//
//  CheckIfItIsAStraightLine .swift
//  LeetCode-main
//
//  Created by jackma on 2023/3/2.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

extension Solution {
    func CheckIfItIsAStraightLine(_ coordinates: [[Int]]) -> Bool {
        // build Bivariate-Function based on two points
        let point1: Array<Int> = coordinates.first!
        let point2: Array<Int> = coordinates.last!
        if (point2.first!-point1.first!) == 0 {
            // same point-x
            for point in coordinates {
                if point.first != point1.first {
                    return false
                }
            }
        } else if (point2.last!-point1.last!) == 0 {
            // same point-y
            for point in coordinates {
                if point.last != point1.last {
                    return false
                }
            }
        } else {
            // Function formula：y=ax+b，get a&b by two points
            let a:Double = Double(point1.last!-point2.last!) / Double(point1.first!-point2.first!)
            let b:Double = Double(point1.last!) - a * Double(point1.first!)
            
            for point in coordinates {
                let y = a*Double(point.first!)+b
                if y != Double(point.last!) {
                    return false
                }
            }
        }
        
        return true
    }
}
