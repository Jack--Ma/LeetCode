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

using namespace std;

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

int main(int argc, const char * argv[]) {
    cout << romanToInt("MCMXCVI") << endl;
    return 0;
}
