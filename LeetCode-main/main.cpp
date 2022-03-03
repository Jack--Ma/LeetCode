//
//  main.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/16.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <iostream>
#include "PathSum.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> nums = {5,4,8,11,4,13,4,7,2,1,2,NullTreeNodeVal,3,4};
    outputTree(buildTree(nums));
    return 0;
}
