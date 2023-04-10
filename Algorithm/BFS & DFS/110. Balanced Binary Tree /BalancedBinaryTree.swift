//
//  BalancedBinaryTree.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/4/8.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/balanced-binary-tree
 
 Given a binary tree, determine if it is height-balanced.
 */

extension Solution {
    func _isBalanced_DFS(_ root: TreeNode?, _ depth: Int, _ result: inout Bool) -> Int {
        if root == nil {
            return depth
        }
        var leftTreeDepth = depth+1
        var rightTreeDepth = depth+1
        if let left = root?.left {
            leftTreeDepth = _isBalanced_DFS(left, depth+1, &result)
        } 
        if let right = root?.right {
            rightTreeDepth = _isBalanced_DFS(right, depth+1, &result)
        }
        if (abs(leftTreeDepth-rightTreeDepth) > 1) {
            result = false
        }
        return max(leftTreeDepth, rightTreeDepth)
    }
    
    func BalancedBinaryTree(_ root: TreeNode?) -> Bool {
        var result = true
        _isBalanced_DFS(root, 0, &result)
        return result
    }
}
