//
//  main.cpp
//  32_Longest_Valid_Parentheses
//
//  Created by JackMa on 16/8/12.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

//用剩余栈的栈顶元素位置信息作为当前合法数据的判断依据是比较重要的技巧
int longestVaildParentheses(string s) {
    stack<int> stack;//保存下标
    int start = 0;
    int par_max = 0;
    
    for (int i = 0; i < s.length(); i++) {
        char this_char = s[i];
        
        //凡是'('，都压入栈内
        if (this_char == '(') {
            stack.push(i);
        } else {
            //栈底为空，则略过')'，i+1表示跳过这个字符
            //即：栈内只有'('字符，')'字符不会进栈
            if (stack.empty()) {
                start = i + 1;
            } else {
                //先弹出，中间的括号对数为i-top()
                stack.pop();
                par_max = stack.empty() ? max(par_max, i-start+1) : max(par_max, i-stack.top());
            }
        }
    }
    
    return par_max;
}

int main(int argc, const char * argv[]) {
    string s = ")()())()()(";
    cout << longestVaildParentheses(s) << endl;
    
    return 0;
}
