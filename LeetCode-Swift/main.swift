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
    let node = ListNode.buildListNode([1,4,2,6,8])
    let treeNode = TreeNode.buildTree([1,4,4,TreeNode.Null,2,2,TreeNode.Null,1,TreeNode.Null,6,8,TreeNode.Null,TreeNode.Null,TreeNode.Null,TreeNode.Null,1,3])
//    var matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    
    print(solution.AddToArrayFormOfInteger([1,2,0,0], 34))
}

testSolution()
