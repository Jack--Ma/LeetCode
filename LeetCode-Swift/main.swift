//
//  main.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/2/20.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

class Solution {

}

func testSolution() {
    let solution = Solution()
//    let node = ListNode.buildListNode([1,2,3,4,5])
    let treeNode = TreeNode.buildTree([1,2,2,3,3,TreeNode.Null,TreeNode.Null,4,4])
//    var matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    print(solution.BalancedBinaryTree(treeNode))
}

testSolution()
