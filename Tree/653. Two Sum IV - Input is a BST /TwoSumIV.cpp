//
//  TwoSumIV.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <unordered_set>
#include "TwoSumIV.hpp"

/**
 Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 Input: root = [5,3,6,2,4,null,7], k = 9
 Output: true
 
 Input: root = [5,3,6,2,4,null,7], k = 28
 Output: false
 */

static inline void _findTarget_recursion(TreeNode *root, unordered_set<int> &nums, bool &find, int k) {
    if (!root) {
        return;
    }
    _findTarget_recursion(root->left, nums, find, k);
    if ((nums.find(root->val) != nums.end())) {
        find = true;
    }
    nums.insert(k-root->val);
    _findTarget_recursion(root->right, nums, find, k);
}

bool Solution::findTarget(TreeNode *root, int k) {
    unordered_set<int> nums;
    bool find = false;
    _findTarget_recursion(root, nums, find, k);
    return find;
}

void testFindTarget() {
    vector<int> nums = {5,3,6,2,4,NullTreeNodeVal,7};
    cout << Solution().findTarget(buildTree(nums), 9) << endl;
}
