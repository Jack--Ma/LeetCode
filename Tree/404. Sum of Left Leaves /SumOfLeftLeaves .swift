//
//  SumOfLeftLeaves .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/11.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/sum-of-left-leaves
 
 Given the root of a binary tree, return the sum of all left leaves.

 A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
 
 Input: root = [3,9,20,null,null,15,7]
 Output: 24
 Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
 */

extension Solution {
    func SumOfLeftLeaves(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        var sum = 0
        if let left = root.left {
            if left.isLeafNode() {
                sum += left.val
            } else {
                sum += SumOfLeftLeaves(left)
            }
        }
        if let right = root.right {
            sum += SumOfLeftLeaves(right)
        }
        return sum
    }
}
