//
//  LinkedListInBinaryTree.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/4/15.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/linked-list-in-binary-tree
 
 Given a binary tree root and a linked list with head as the first node.

 Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

 In this context downward path means a path that starts at some node and goes downwards.
 */

extension Solution {
    // add property
    struct Holder {
        static var _result:Bool = false
    }
    var result:Bool {
        get {
            return Holder._result
        }
        set(newValue) {
            Holder._result = newValue
        }
    }
    
    func LinkedListInBinaryTree(_ head: ListNode?, _ root: TreeNode?) -> Bool {
        if result {
            return result
        }
        
        _isSubPath_DFS(head, root)
        // loop every node in tree
        if let root = root {
            if let left = root.left {
                let a = LinkedListInBinaryTree(head, left)
            }
            if let right = root.right {
                let b = LinkedListInBinaryTree(head, right)
            }
        }
        return result
    }
    
    func _isSubPath_DFS(_ head: ListNode?, _ root: TreeNode?) {
        if result {
            return
        }
        // return when find all nodes in list
        guard let head = head else {
            result = true
            return
        }
        // return when find left-root
        guard let root = root else {
            return
        }
        if root.val == head.val {
            _isSubPath_DFS(head.next, root.left)
            _isSubPath_DFS(head.next, root.right)
        }
    }
}
