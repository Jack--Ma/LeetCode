//
//  Pow(x, n) .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/14.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/powx-n/
 
 Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
 */

extension Solution {
    func PowXN(_ x: Double, _ n: Int) -> Double {
        if n < 0 {
            return 1.0 / pow_positive(x, -n)
        } else if n > 0 {
            return pow_positive(x, n)
        } else {
            return 1.0
        }
    }
    
    // bad solution
    // when n is 2147483647, timeout
    func pow_positive(_ x: Double, _ n: Int) -> Double {
        if n == 1 {
            return x
        }
        var result = x
        result *= pow_positive(x, n-1)
        
        return result
    }
    
    // best solution
    // time complexity: O(log2n)
    func pow_best(_ x: Double, _ n: Int) -> Double {
        var x = x, n = n, result = 1.0
        
        if n < 0 {
            x = 1.0/x
            n = -n
        }
        
        while n > 0 {
            if n % 2 != 0 {
                result *= x
            }
            x *= x
            n /= 2
        }
        
        return result
    }
}
