//
//  SignOfTheProductOfAnArray .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/2/24.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

extension Solution {
    func SignOfTheProductOfAnArray(_ nums: [Int]) -> Int {
        // MARK: Can not use * mult all numbers
        // ERROR: process exited with signal SIGILL (over flow)
//        var mult = nums.reduce(1, *)
        var mult = 1
        for item in nums {
            mult *= (item > 0 ? 1 : (item < 0 ? -1 : 0))
        }
        
        return (mult > 0 ? 1 : (mult < 0 ? -1 : 0))
    }
}
