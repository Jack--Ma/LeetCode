//
//  BinarySearchTreeIterator.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "BinarySearchTreeIterator.hpp"

/**
 Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

 Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

 Input
 ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
 [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
 Output
 [null, 3, 7, true, 9, true, 15, true, 20, false]

 Explanation
 BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
 bSTIterator.next();    // return 3
 bSTIterator.next();    // return 7
 bSTIterator.hasNext(); // return True
 bSTIterator.next();    // return 9
 bSTIterator.hasNext(); // return True
 bSTIterator.next();    // return 15
 bSTIterator.hasNext(); // return True
 bSTIterator.next();    // return 20
 bSTIterator.hasNext(); // return False
 */

void testBSTIterator() {
    vector<int> nums = {7, 3, 15, NullTreeNodeVal, NullTreeNodeVal, 9, 20};
    TreeNode *root = buildTree(nums);
    BSTIterator iter = BSTIterator(root);
    cout << iter.next() << endl;
    cout << iter.next() << endl;
    cout << iter.hasNext() << endl;
    cout << iter.next() << endl;
    cout << iter.hasNext() << endl;
    cout << iter.next() << endl;
    cout << iter.hasNext() << endl;
    cout << iter.next() << endl;
    cout << iter.hasNext() << endl;
}

static inline void _BSTIterator_inorderTraverse(TreeNode *root, vector<int> &nums) {
    if (!root) {
        return;
    }
    _BSTIterator_inorderTraverse(root->left, nums);
    nums.push_back(root->val);
    _BSTIterator_inorderTraverse(root->right, nums);
}

/// Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
BSTIterator::BSTIterator(TreeNode* root) {
    nums = vector<int>();
    _BSTIterator_inorderTraverse(root, nums);
    index = 0;
}

/// Moves the pointer to the right, then returns the number at the pointer.
int BSTIterator::next() {
    return nums[index++];
}

/// Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
bool BSTIterator::hasNext() {
    return index < nums.size();
}
