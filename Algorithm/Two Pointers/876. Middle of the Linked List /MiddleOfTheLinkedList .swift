//
//  MiddleOfTheLinkedList .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/9.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/middle-of-the-linked-list
 
 Given the head of a singly linked list, return the middle node of the linked list.

 If there are two middle nodes, return the second middle node.
 */

extension Solution {
    func MiddleOfTheLinkedList(_ head: ListNode?) -> ListNode? {
        if head == nil {
            return head
        }
        let zeroHead = ListNode(0, head)
        var curr:Optional = zeroHead, prev:Optional = zeroHead
        while curr != nil || prev != nil {
            // prev is the middle of list
            if curr == nil {
                return prev
            }
            // curr speed is 2x
            if let currNext = curr!.next {
                curr = currNext.next
            } else {
                curr = nil
            }
            // prev speed is 1x
            if let prevNext = prev!.next {
                prev = prevNext
            }
        }
        
        return nil
    }
}
