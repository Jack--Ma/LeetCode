//
//  main.cpp
//  94-Binary_Tree_Inorder_Traversal
//
//  Created by JackMa on 16/9/4.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Method 1, DFS
void inorder(TreeNode *root, vector<int> &result) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    inorder(root, result);
    
    return result;
}

//Method 2, Use stack presents a DFS search
vector<int> inorderTraversal2(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> stack;
    
    while (root != NULL || !stack.empty()) {
        if (root != NULL) {
            stack.push(root);
            root = root->left;
        } else {
            root = stack.top();
            result.push_back(root->val);
            stack.pop();
            root = root->right;
        }
    }
    return result;
}

//层次遍历生成二叉树
TreeNode buildTree(vector<int> &nums) {
    if (nums.size() == 0) {
        return NULL;
    }
    
    TreeNode *node = NULL, *root = NULL;
    int parent_num = 1;//指向当前结点的父结点
    vector<TreeNode *> nodes(1024, NULL);
    for (int i = 0; i < nums.size(); i++) {
        node = NULL;
        if (nums[i] != 0) {
            node = new TreeNode(nums[i]);
        }
        nodes[i+1] = node;
        if (i == 0) {
            root = node;
        } else {
            if (node && nodes[parent_num]) {
                if ((i+1) % 2 == 0) {
                    nodes[parent_num]->left = node;
                } else {
                    nodes[parent_num]->right = node;
                }
                if ((i+1) % 2 == 1) {
                    parent_num++;
                }
            }
        }
    }
    
    return *root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1, NULL, 2, 3};
    TreeNode tree = buildTree(nums);
    vector<int> result = inorderTraversal(&tree);
    
    return 0;
}
