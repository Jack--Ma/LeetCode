//
//  KthSmallestElementInABST.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef KthSmallestElementInABST_hpp
#define KthSmallestElementInABST_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k);
};

void testKthSmallest();

#endif /* KthSmallestElementInABST_hpp */
