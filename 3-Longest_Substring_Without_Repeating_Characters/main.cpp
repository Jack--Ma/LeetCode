//
//  main.cpp
//  3-Longest_Substring_Without_Repeating_Characters
//
//  Created by JackMa on 16/7/31.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//hash method
int otherLengthOfLongestSubstring(string s) {
    int max_len = 0;
    const int ASCII_MAX = 255;
    int last[ASCII_MAX];//为每一个字符建立的数组，数组下标代表着字符的ASCII，值代表这个字符所在的位置
    fill(last, last+ASCII_MAX, -1);//初始化位置-1
    
    int i = 0;
    int start = 0;
    while (i < s.size()) {
        //表示s[i]这个字符已经出现过
        if (last[s[i]] >= start) {
            max_len = max(i - start, max_len);
            start = last[s[i]] + 1;
        }
        last[s[i]] = i;
        i++;
    }
    
    //若在start后所有字符只出现了一次，那么上面循环的if语句就没有调用
    return max(max_len, int(s.size() - start));
}

int lengthOfLongestSubstring(string s) {
    int len = 0;
    
    if (s.size() < 2) {
        return int(s.size());
    }
    
    for (int i = 0; i < s.size(); i++) {
        string sub_string = "";
        sub_string += s[i];
        
        for (int j = i+1; j < s.size(); j++) {
            string temp_string;
            temp_string = temp_string.assign(s, i, j-i);
            
            size_t t = temp_string.find(s[j]);
            if (t == string::npos) {
                sub_string.push_back(s[j]);
                len = max(len, int(sub_string.size()));
            } else {
                len = max(len, int(temp_string.size()));
                break;
            }
        }
    }
    
    return len;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string str = "abcdaef";
    cout << otherLengthOfLongestSubstring(str) << endl;
    
    return 0;
}
