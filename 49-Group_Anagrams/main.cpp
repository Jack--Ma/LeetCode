//
//  main.cpp
//  49-Group_Anagrams
//
//  Created by JackMa on 16/8/7.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//Time Limit Exceeded2
//vector<vector<string>> groupAnagrams(vector<string> &strs) {
//    vector<vector<string>> result(strs.size());
//    
//    for (int i = 0; i < strs.size(); i++) {
//        string this_str = strs[i];//当前的str
//        result[i].push_back(this_str);//加入
//        for (int j = i+1; j < strs.size(); j++) {
//            string next_str = strs[j];//下一个str
//
//            if (this_str.size() != next_str.size()) {
//                continue;
//            }
//            //判断两个str是否相等
//            string temp_this_str = this_str;
//            sort(temp_this_str.begin(), temp_this_str.end());
//            
//            string temp_next_str = next_str;
//            sort(temp_next_str.begin(), temp_next_str.end());
//            
//            if (temp_this_str == temp_next_str) {
//                //若相等，加入next_str后删除strs内的next_str
//                //由于strs缩短，因此j--
//                result[i].push_back(next_str);
//                auto temp = strs.begin();
//                temp += j;
//                strs.erase(temp);
//                j--;
//            }
//        }
//    }
//    //取strs剩余个数
//    vector<vector<string>> temp;
//    temp.assign(result.begin(), result.begin()+strs.size());
//    return temp;
//}

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<int>> map;
    
    //构造map，key为有序排列的一个string，value为strs内符合要求的string的位置数组
    for (int i = 0; i < strs.size(); i++) {
        string temp_str = strs[i];
        sort(temp_str.begin(), temp_str.end());
        
        map[temp_str].push_back(i);
    }
    
    //遍历map，找到每一个位置数组，加入result中
    vector<vector<string>> result(map.size());
    int k = 0;
    for (auto i = map.begin(); i != map.end(); i++) {
        vector<int> positions = i->second;
        for (int j = 0; j < positions.size(); j++) {
            string str = strs[positions[j]];
            result[k].push_back(str);
        }
        k++;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //["eat", "tea", "tan", "ate", "nat", "bat"]
    //["","",""]
    //["ray","cod","abe","ned","arc","jar","owl","pop","paw","sky","yup","fed","jul","woo","ado","why","ben","mys","den","dem","fat","you","eon","sui","oct","asp","ago","lea","sow","hus","fee","yup","eve","red","flo","ids","tic","pup","hag","ito","zoo"]
    //["hos","boo","nay","deb","wow","bop","bob","brr","hey","rye","eve","elf","pup","bum","iva","lyx","yap","ugh","hem","rod","aha","nam","gap","yea","doc","pen","job","dis","max","oho","jed","lye","ram","pup","qua","ugh","mir","nap","deb","hog","let","gym","bye","lon","aft","eel","sol","jab"]
    vector<string> strs = {"ray","cod","abe","ned","arc","jar","owl","pop","paw","sky","yup","fed","jul","woo","ado","why","ben","mys","den","dem","fat","you","eon","sui","oct","asp","ago","lea","sow","hus","fee","yup","eve","red","flo","ids","tic","pup","hag","ito","zoo"};
    vector<vector<string>> result = groupAnagrams(strs);
    
    return 0;
}
