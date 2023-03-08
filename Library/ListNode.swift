//
//  ListNode.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/9.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

public class ListNode {
    public var val: Int
    public var next: ListNode?
    
    public convenience init() {
        self.init(0, nil)
    }
    
    public convenience init(_ val: Int) {
        self.init(val, nil)
    }
    
    public init(_ val: Int, _ next: ListNode?) {
        self.val = val
        self.next = next
    }
}

extension ListNode {
    
    /// Build a list with nums
    /// - Parameter nums: nums
    /// - Returns: list head
    static func buildListNode(_ nums: [Int]) -> ListNode? {
        var root = ListNode()
        
        var curr = root
        for num in nums {
            let node = ListNode(num)
            curr.next = node
            if let next = curr.next {
                curr = next
            }
        }
        
        return root.next
    }
    
}
