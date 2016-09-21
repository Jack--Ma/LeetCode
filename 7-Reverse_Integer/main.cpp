//
//  main.cpp
//  7-Reverse_Integer
//
//  Created by JackMa on 16/9/21.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int reverse(int x) {
    vector<int> nums;
    while (x != 0) {
        nums.push_back(x % 10);
        x = x / 10;
    }
    
    int result = 0;
    const int N = int(nums.size());
    for (int i = N-1; i >= 0; i--) {
        result += pow(10, i) * nums[N-i-1];
        //考虑32位、64位INT越界问题
        if (result == INT_MIN) {
            return 0;
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    cout << reverse(-1000000003) << endl;
    return 0;
}
