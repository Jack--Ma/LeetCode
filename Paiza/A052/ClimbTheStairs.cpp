//
//  ClimbTheStairs.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ClimbTheStairs.hpp"
#include "TreeNode.hpp"

/**
 入力例1
 8
 3 5
 出力例1
 4
 
 入力例2
 10
 2 4
 出力例2
 5
 */

void _climbTheStairs_recursion(TreeNode *root, unordered_set<int>& set, int count, int A, int B) {
    if (set.find(root->val) != set.end()) {
        return;
    }
    set.insert(root->val);
    if ((root->val + A) < count) {
        TreeNode *leftNode = new TreeNode(root->val+A);
        _climbTheStairs_recursion(leftNode, set, count, A, B);
    }
    if ((root->val + B) < count) {
        TreeNode *rightNode = new TreeNode(root->val+B);
        _climbTheStairs_recursion(rightNode, set, count, A, B);
    }
}

void testClimbTheStairs() {
    string str;
    getline(cin, str);
    const int stairCount = stoi(str);
    
    getline(cin, str);
    const int A = stoi(string_split(str, " ")[0]);
    const int B = stoi(string_split(str, " ")[1]);
    
    unordered_set<int> stairIndexSet;
    TreeNode *root = new TreeNode(0);
    _climbTheStairs_recursion(root, stairIndexSet, stairCount, A, B);
    
    cout << (stairCount - stairIndexSet.size()) << endl;
}
