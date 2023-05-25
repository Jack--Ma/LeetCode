//
//  N-aryTreeLevelOrderTraversal .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/5/25.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/n-ary-tree-level-order-traversal
 
 Given an n-ary tree, return the level order traversal of its nodes' values.

 Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
 */

extension Solution {
    func NAryTreeLevelOrderTraversal(_ root: Node?) -> [[Int]] {
        guard let root = root else {
            return [[]]
        }
        
        var result = [[Int]]()
        var nodes = [Node?]()
        nodes.append(root)
        
        while !nodes.isEmpty {
            var nums = [Int]()
            var nextNodes = [Node?]()
            
            for node in nodes {
                if let node = node {
                    nums.append(node.val)
                    nextNodes.append(contentsOf: node.children)
                }
            }
            result.append(nums)
            nodes = nextNodes
        }
        
        return result
    }
    
//    dfs(root, 0)
//    return result

//    private var result: [[Int]] = []
//    private func dfs(_ root: Node?, _ level: Int) {
//        guard let root = root else { return }
//        if level == result.count {
//            let array = [root.val]
//            result.append(array)
//        } else {
//            result[level] += [root.val]
//        }
//        for child in root.children {
//            dfs(child, level + 1)
//        }
//    }
}
