//
//  CanMakeArithmeticProgressionFromSequence .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/2/26.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

extension Solution {
    func CanMakeArithmeticProgressionFromSequence(_ arr: [Int]) -> Bool {
        var result = true
        
        let _arr = arr.sorted(by: <)
        let diff = _arr[1] - _arr[0]
        for i in 1..<_arr.count-1 {
            if ((_arr[i+1] - _arr[i]) != diff) {
                result = false
                break
            }
        }
        
        return result
    }
}
