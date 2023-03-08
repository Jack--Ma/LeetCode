//
//  ConvertBinaryNumberInALinkedListToInteger .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/8.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
 
 Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

 Return the decimal value of the number in the linked list.

 The most significant bit is at the head of the linked list.
 */

extension Solution {
    func ConvertBinaryNumberInALinkedListToInteger(_ head: ListNode?) -> Int {
        var nums = [Int]()
        
        var curr = head
        while let _curr = curr {
            nums.append(_curr.val)
            curr = _curr.next
        }
        
        var result = 0
        for (i, num) in nums.enumerated() {
            result += num * Int(pow(2.0, Double(nums.count-1-i)))
        }
        
        return result
        
        // Better solution
//        var res = 0, node = head
//        while node != nil {
//            res = res * 2 + node!.val
//            node = node?.next
//        }
//
//        return res
        
    }
}
