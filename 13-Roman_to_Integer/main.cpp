//
//  main.cpp
//  13-Roman_to_Integer
//
//  Created by JackMa on 2016/9/26.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//normal method, time is O(n^2)
int romanToInt(string s) {
    int result = 0;
    vector<string> keys = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    
    for (int i = 0; i < s.size(); i++) {
        string temp1, temp2;
        temp1 = temp1.assign(s, i, 1);
        temp2 = temp2.assign(s, i, 2);
        for (int j = 0; j < keys.size(); j++) {
            if (j % 2 == 0) {
                if (temp1 == keys[j]) {
                    result += values[j];
                    break;
                }
            } else {
                if (temp2 == keys[j]) {
                    result += values[j];
                    i++;
                    break;
                }
            }
        }
    }
    
    return result;
}

//best method, time is O(n)
int romanToInt_best(string s) {
    int result = 0;
    unordered_map<char, int> map = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}};
    
    for (int i = 0; i < s.size(); i++) {
        if (map.count(s[i]) == 0) return 0;
        result += map[s[i]];
        //若当前字符大于前一个字符，说明这两个字符是一个整体，则需要减掉上一个字符对应的值
        if (i != 0 && map[s[i]] > map[s[i-1]]) {
            result -= 2*(map[s[i-1]]);
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    cout << romanToInt("MCMXCVI") << endl;
    cout << romanToInt_best("MCMXCVI") << endl;
    return 0;
}
