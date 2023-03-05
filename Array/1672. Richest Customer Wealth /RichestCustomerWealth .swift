//
//  RichestCustomerWealth .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/6.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

extension Solution {
    /**
     https://leetcode.com/problems/richest-customer-wealth
     
     You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

     A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.
     */
    
    func RichestCustomerWealth(_ accounts: [[Int]]) -> Int {
        var result = 0
        
        for account in accounts {
            var sum = 0
            account.forEach { num in
                sum+=num
            }
            result = max(sum, result)
        }
        
        return result
    }
}
