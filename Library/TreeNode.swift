//
//  TreeNode.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/11.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    
    public convenience init() {
        self.init(0, nil, nil)
    }
    
    public convenience init(_ val: Int) {
        self.init(val, nil, nil)
    }
    
    public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
        self.val = val
        self.left = left
        self.right = right
    }
    
    // null node
    static let Null = LONG_MAX
}

extension TreeNode {
    static func buildTree(_ nums: [Int]) -> TreeNode? {
        return _buildTree(nums, 0)
    }
    
    static func _buildTree(_ nums: [Int], _ k: Int) -> TreeNode? {
        var root: TreeNode?
        if (k < nums.count && nums[k] != Null) {
            root = TreeNode(nums[k])
            root!.left = _buildTree(nums, 2*k+1)
            root!.right = _buildTree(nums, 2*k+2)
        }
        return root
    }
    
    func findTreeDepth(_ depth: Int) -> Int {
        var leftDepth = depth, rightDepth = depth
        if let left = self.left {
            leftDepth = left.findTreeDepth(depth+1)
        }
        if let right = self.right {
            rightDepth = right.findTreeDepth(depth+1)
        }
        return max(leftDepth, rightDepth)
    }
    
    func isLeafNode() -> Bool {
        if self.left != nil || self.right != nil {
            return false
        }
        return true
    }
    
    func printTree() {
        
    }
}
