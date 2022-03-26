//
//  BinarySearchTreeIterator.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef BinarySearchTreeIterator_hpp
#define BinarySearchTreeIterator_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/binary-search-tree-iterator/
class BSTIterator {
private:
    vector<int> nums;
    int index;
    
public:
    BSTIterator(TreeNode* root);
    
    int next();
    
    bool hasNext();
};

void testBSTIterator();

#endif /* BinarySearchTreeIterator_hpp */
