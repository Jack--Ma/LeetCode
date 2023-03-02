//
//  N-aryTreePreorderTraversal .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/1.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/n-ary-tree-preorder-traversal
 
 Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

 Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)
 
 Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 */

extension Solution {
    func NaryTreePreorderTraversal(_ root: Node?) -> [Int] {
        var result: Array<Int> = []
        NaryTreePreorderTraversal_recursion(root, &result)
        return result
    }
    
    // preorder traverse by use recursion
    func NaryTreePreorderTraversal_recursion(_ root: Node?, _ nums: inout [Int]) {
        if let root = root {
//            print("\(root.val) ", terminator: "")
            nums.append(root.val)
            for node in root.children {
                NaryTreePreorderTraversal_recursion(node, &nums)
            }
        }
    }
}
