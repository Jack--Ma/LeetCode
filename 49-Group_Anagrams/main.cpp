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

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> result(strs.size());
    
    for (int i = 0; i < strs.size(); i++) {
        string this_str = strs[i];
        result[i].push_back(this_str);
        for (int j = i+1; j < strs.size(); j++) {
            string next_str = strs[j];

            if (this_str.size() != next_str.size()) {
                continue;
            }
            string temp_this_str = this_str;
            sort(temp_this_str.begin(), temp_this_str.end());
            
            string temp_next_str = next_str;
            sort(temp_next_str.begin(), temp_next_str.end());
            
            if (temp_this_str == temp_next_str) {
                result[i].push_back(next_str);
                auto temp = strs.begin();
                temp += j;
                strs.erase(temp);
                j--;
            }
        }
    }
    
    vector<vector<string>> temp;
    temp.assign(result.begin(), result.begin()+strs.size());
    return temp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //["eat", "tea", "tan", "ate", "nat", "bat"]
    //["","",""]
    //["ray","cod","abe","ned","arc","jar","owl","pop","paw","sky","yup","fed","jul","woo","ado","why","ben","mys","den","dem","fat","you","eon","sui","oct","asp","ago","lea","sow","hus","fee","yup","eve","red","flo","ids","tic","pup","hag","ito","zoo"]
    //["hos","boo","nay","deb","wow","bop","bob","brr","hey","rye","eve","elf","pup","bum","iva","lyx","yap","ugh","hem","rod","aha","nam","gap","yea","doc","pen","job","dis","max","oho","jed","lye","ram","pup","qua","ugh","mir","nap","deb","hog","let","gym","bye","lon","aft","eel","sol","jab"]
    vector<string> strs = {""};
    vector<vector<string>> result = groupAnagrams(strs);
    
    return 0;
}
