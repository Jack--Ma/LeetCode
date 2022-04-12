//
//  Node.hpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/12.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* buildNodeTree(vector<int> nums);

#endif /* Node_hpp */
