//
//  SerializeAndDeserializeBinaryTree.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/27.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include "SerializeAndDeserializeBinaryTree.hpp"

/**
 Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
 
 Input: root = [1,2,3,null,null,4,5]
 Output: [1,2,3,null,null,4,5]
 */

void testSerializeAndDeserializeBinaryTree() {
    vector<int> nums = {};
    TreeNode *root = buildTree(nums);
    Codec codec = Codec();
    string encodeStr = codec.serialize(root);
    cout << encodeStr << endl;
    TreeNode *decodeRoot = codec.deserialize(encodeStr);
    outputTree(decodeRoot);
}

/// serialize tree by preorder traverse
string _serialize_preorder(TreeNode *root) {
    if (!root) {
        return "NULL,";
    }
    string valStr = to_string(root->val) + ",";
    string left = _serialize_preorder(root->left);
    string right = _serialize_preorder(root->right);
    return valStr + left + right;
}

/// deserialize queue by preorder traverse
TreeNode* _deserialize_preorder(queue<string> &q) {
    // each s represent a node in tree
    string s = q.front();
    q.pop();
    // find empty node, just return NULL
    if (s == "NULL") {
        return NULL;
    }
    // recurse root node left and right
    TreeNode *root = new TreeNode(stoi(s));
    root->left = _deserialize_preorder(q);
    root->right = _deserialize_preorder(q);
    return root;
}

/// serialize tree by BFS traverse
string _serialize_BFS(TreeNode *root) {
    string result = "";
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    
    while (!nodeQueue.empty()) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();
        if (node) {
            result += (to_string(node->val) + ",");
            nodeQueue.push(node->left);
            nodeQueue.push(node->right);
        } else {
            result += "NULL,";
        }
    }
    
    // such as: 4,-7,-3,NULL,NULL,-9,-3,NULL,NULL,NULL,NULL,
    return result;
}

/// deserialize string by use BFS
TreeNode* _deserialize_BFS(string data) {
    // 1st. change data to string array
    // strList such as: [4,-7,-3,NULL,NULL,-9,-3,NULL,NULL,NULL,NULL]
    vector<string> strList;
    string str = "";
    for (int i = 0; i < data.length(); i++) {
        if (data[i] == ',') {
            strList.push_back(str);
            str = "";
            continue;
        }
        str.push_back(data[i]);
    }

    string rootStr = strList.front();
    // handle with NULL case
    if (rootStr == "NULL") {
        return NULL;
    }
    
    // build root node
    TreeNode *root = new TreeNode(stoi(rootStr));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    
    // 2rd. build tree with traverse str list
    for (int i = 1; i < strList.size() - 1; i+=2) {
        TreeNode *parentNode = nodeQueue.front();
        nodeQueue.pop();
        // synchronously handle with left and right node
        string leftStr = strList[i], rightStr = strList[i+1];
        if (leftStr != "NULL") {
            TreeNode *leftNode = new TreeNode(stoi(leftStr));
            parentNode->left = leftNode;
            nodeQueue.push(leftNode);
        }
        if (rightStr != "NULL") {
            TreeNode *rightNode = new TreeNode(stoi(rightStr));
            parentNode->right = rightNode;
            nodeQueue.push(rightNode);
        }
    }
    
    return root;
}

/// encode serialize tree to string
string Codec::serialize(TreeNode* root) {
    return _serialize_BFS(root);
}

/// decode deserialize string to tree
TreeNode* Codec::deserialize(string data) {
    return _deserialize_BFS(data);
    
    queue<string> q;
    string s;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == ',') {
            q.push(s);
            s = "";
            continue;
        }
        s += data[i];
    }
    if (s.size() != 0) {
        q.push(s);
    }
    return _deserialize_preorder(q);
}
