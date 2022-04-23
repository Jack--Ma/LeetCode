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

extern int NullTreeNodeVal;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/// Build tree with int vector
/// @note Use NullTreeNodeVal represent Null node
TreeNode* buildTree(vector<int> nums);

/// Find key node with preorder traverse
TreeNode* findTreeNode(TreeNode *root, int key);

/// Judge node is leaf or not
bool isLeafNode(TreeNode *node);

/// Judge two trees are same or not by use preorder traverse
bool isSameTree(TreeNode *root1, TreeNode *root2);

/// Output tree by use BFS traverse
void outputTree(TreeNode *root);

#endif /* TreeNode_hpp */
