//
//  main.cpp
//  12-Integer_to_Roman
//
//  Created by JackMa on 2016/9/26.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string intToRoman(int num) {
    string result = "";
    vector<string> keys = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    
    for (int i = 0; i < values.size(); i++) {
        int number = num / values[i];
        if (number == 0) {
            continue;
        }
        num = num % values[i];
        for (int j = 0; j < number; j++) {
            result.append(keys[i]);
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    cout << intToRoman(1323) << endl;
    return 0;
}
