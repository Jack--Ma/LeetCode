//
//  SerializeAndDeserializeBinaryTree.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/27.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef SerializeAndDeserializeBinaryTree_hpp
#define SerializeAndDeserializeBinaryTree_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root);

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data);
};

void testSerializeAndDeserializeBinaryTree();

#endif /* SerializeAndDeserializeBinaryTree_hpp */
