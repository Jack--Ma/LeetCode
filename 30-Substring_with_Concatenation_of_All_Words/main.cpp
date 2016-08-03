//
//  main.cpp
//  30-Substring_with_Concatenation_of_All_Words
//
//  Created by JackMa on 16/8/1.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result = {};
    int M = int(words.size());
    int N = int(words.at(0).size());
    
    if (s.size() < N*M) {
        return result;
    }
    //确定遍历次数
    int num = int(s.size()) - N*M;
    for (int i = 0; i <= num; i++) {
        //在s中获取i开始的N*M个字符
        string sub_str;
        sub_str = sub_str.assign(s, i, N*M);
        int min_position = INT_MAX;
        bool is_exit = true;
        size_t last_position = 0;
        //遍历M次
        for (int j = 0; j < M; j++) {
            size_t position = sub_str.find(words[j], last_position);
            if (position == string::npos) {
                //未找到，直接跳出
                is_exit = false;
                break;
            } else if (position % N != 0) {
                //找到，但是位置不符合，跳过此位置，注意j--
                //每一个正确的位置都应该是0 N 2N 3N....
                last_position = position + 1;
                j--;
                continue;
            } else {
                //找到正确的位置，记录min_position
                min_position = min(int(position)+i, min_position);
                last_position = 0;
                //消去已找到的字符
                for (int k = int(position); k < position+N; k++) {
                    sub_str[k] = ' ';
                }
            }
        }
        if (is_exit) {
            result.push_back(min_position);
        }
    }
    
    return result;
}
/*
 "lingmindraboofooowingdingbarrwingmonkeypoundcake"
 ["fooo","barr","wing","ding","wing"]
 "aaaaaaaa"
 ["aa","aa","aa"]
 "ababaab"
 ["ab","ba","ba"]
 */
int main() {
    string str = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> words = {"fooo","barr","wing","ding","wing"};
    vector<int> result = findSubstring(str, words);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}
