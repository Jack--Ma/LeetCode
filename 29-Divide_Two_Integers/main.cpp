//
//  main.cpp
//  29-Divide_Two_Integers
//
//  Created by JackMa on 2016/9/29.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

//不能使用乘除和取余，因此使用移位进行运算
int divide(int dividend, int divisor) {
    if (divisor == 0) return INT_MAX;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    
    //确定结果符号
    int flag = true;
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) flag = false;
    
    //取得unsigned值，防止溢出
    unsigned long dvd = abs(long(dividend));
    unsigned long dvs = abs(long(divisor));
    
    int result = 0;
    while (dvd >= dvs) {
        int i = 0;
        while (dvs<<(i) <= dvd) i++;//取得当前dvs*2^(i)大于dvd的时候的i的值
        result += pow(2, i-1);//结果加上2^(i-1)
        dvd -= dvs * pow(2, i-1);//被除数减去dvs*2^(i-1)
    }
    
    return flag ? result : -result;
}

int main(int argc, const char * argv[]) {
    cout << divide(32, 33) << endl;
    return 0;
}
