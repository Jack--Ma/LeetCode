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
    var matrix = [[1,2,3],[4,5,6],[7,8,9]]
    print(solution.ArithmeticSubarrays([4,6,5,9,3,7], [0,0,2], [2,3,5]))
}

testSolution()
