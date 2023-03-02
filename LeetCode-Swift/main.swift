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
    let nums =  [1,Node.Null,2,3,4,5,Node.Null,Node.Null,6,7,Node.Null,8,Node.Null,9,10,Node.Null,Node.Null,11,Node.Null,12,Node.Null,13,Node.Null,Node.Null,14]
    let node = Node.buildTree(nums)
    if let node = node {
        node.printTree()
    }
    print(solution.NaryTreePreorderTraversal(node))
}

testSolution()
