//
//  TreeNode.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(vector<int> nums);

void outputTree(TreeNode *node);

#endif /* TreeNode_hpp */
