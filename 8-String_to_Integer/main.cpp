//
//  main.cpp
//  8-String_to_Integer
//
//  Created by JackMa on 16/9/21.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int myAtoi(string str) {
    //去掉首尾空格
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    //判断正负
    int flag = 1;
    int i = 0;
    if (str[0] == '-' || str[0] == '+') {
        flag = str[0] == '-' ? -1 : 1;
        str[0] = '0';
    }

    const int N = int(str.size());
    long long num = 0;
    for (; i < N; i++) {
        if (str[i] < '0' || str[i] > '9') break;
        num = num * 10 + (str[i] - '0');
        if (num > INT_MAX) break;
    }
    num *= flag;
    if (num > INT_MAX) return INT_MAX;
    if (num < INT_MIN) return INT_MIN;
    return num;
}

int main(int argc, const char * argv[]) {
    cout << myAtoi("   -aaa") << endl;
    return 0;
}
