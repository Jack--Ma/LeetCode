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
    var matrix = [[1,1,3],[1,5,3],[7,2,2]]
//    var nums = [6,10,6,9,7,8]
    print(solution.solution6(&matrix))
}

testSolution()
