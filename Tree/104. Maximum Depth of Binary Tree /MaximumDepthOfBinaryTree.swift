//
//  MaximumDepthOfBinaryTree.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/11.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/maximum-depth-of-binary-tree
 
 Given the root of a binary tree, return its maximum depth.

 A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

extension Solution {
    func MaximumDepthOfBinaryTree(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        return root.findTreeDepth(1)
    }
}
