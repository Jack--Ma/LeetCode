//
//  main.cpp
//  76-Minimum_Window_Substring
//
//  Created by JackMa on 16/8/8.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string minWindow(string S, string T) {
    if (S.empty()) {
        return "";
    }
    if (S.size() < T.size()) {
        return "";
    }
    
    const int ASCII_MAX = 256;
    int appeared_count[ASCII_MAX];//记录窗口内T中字符的数量
    int expected_count[ASCII_MAX];//记录S中各个字符出现的次数
    fill(appeared_count, appeared_count + ASCII_MAX, 0);
    fill(expected_count, expected_count + ASCII_MAX, 0);
    for (int i = 0; i < T.size(); i++) {
        expected_count[T[i]]++;
    }
    int minWidth = INT_MAX, min_start = 0;//最小窗口位置与长度
    int window_start = 0;
    int appeared = 0;//窗口内满足条件的字符的个数
    
    for (int window_end = 0; window_end < S.size(); window_end++) {
        char end_char = S[window_end];
        //S[window_end] 字符在T中存在，不存在则直接跳过
        if (expected_count[end_char] > 0)  {
            appeared_count[end_char]++;//出现次数加1
            if (appeared_count[end_char] <= expected_count[end_char]) {
                appeared++;
            }
        }
        //个数满足
        if (appeared == T.size()) {
            char start_char = S[window_start];
            //appeared_count[start_char] > expected_count[start_char]：表示窗口内start_char字符数量大于T中start_char字符数量
            //expected_count[start_char] == 0：表示start_char字符不在T中
            //上面两种情况，都跳过字符，在appeared_count对其数量减一
            while (appeared_count[start_char] > expected_count[start_char] || expected_count[start_char] == 0) {
                appeared_count[start_char]--;
                window_start++;
                start_char = S[window_start];
            }
            //此时窗口为符合条件的
            if (minWidth > (window_end - window_start + 1)) {
                minWidth = window_end - window_start + 1;
                min_start = window_start;
            }
        }
    }
    
    if (minWidth == INT_MAX)  {
        //T中有S中不存在的字符
        return "";
    } else {
        return S.substr(min_start, minWidth);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "ADOBECODEBANC", t = "ABCY";
    cout << minWindow(s, t) << endl;
    
    return 0;
}
