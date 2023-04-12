//
//  MinimumDepthOfBinaryTree .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/4/10.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/minimum-depth-of-binary-tree
 
 Given a binary tree, find its minimum depth.

 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 Note: A leaf is a node with no children.
 */

extension Solution {
    func _findMinDepth(_ root: TreeNode?, _ depth: Int, _ minDepth: inout Int) {
        guard let root = root else { return }
        // find lead node
        if root.isLeafNode() {
            minDepth = min(minDepth, depth+1)
        }
        
        _findMinDepth(root.left, depth+1, &minDepth)
        _findMinDepth(root.right, depth+1, &minDepth)
    }
    
    func MinimumDepthOfBinaryTree(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        var minDepth = LONG_MAX
        _findMinDepth(root, 0, &minDepth)
        return minDepth
    }
}
