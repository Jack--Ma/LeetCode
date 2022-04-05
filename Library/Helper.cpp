//
//  Helper.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/7.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "Helper.hpp"

void printVector(const vector<int> &v) {
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

void printVector(const vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        printVector(v[i]);
    }
}

vector<string> string_split(const string &str, const string &pattern) {
    vector<string> res;
    if (str == "")
        return res;
    //在字符串末尾也加入分隔符，方便截取最后一段
    string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while (pos != strs.npos) {
        string temp = strs.substr(0, pos);
        res.push_back(temp);
        //去掉已分割的字符串,在剩下的字符串中进行分割
        strs = strs.substr(pos+1, strs.size());
        pos = strs.find(pattern);
    }

    return res;
}
