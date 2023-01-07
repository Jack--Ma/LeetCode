//
//  B096.cpp
//  LeetCode-main
//
//  Created by jackma on 2023/1/7.
//  Copyright © 2023 JackMa. All rights reserved.
//

/**
 https://paiza.jp/challenges/472/ready
 
 入力は以下のフォーマットで与えられます。

 H W
 s_1
 s_2
 ...
 s_H
 ・1 行目には、フィールドの行数、列数を表す整数 H, W がこの順でスペース区切りで与えられます。
 ・続く H 行のうちの i 行目 (1 ≦ i ≦ H) には半角記号 "." および "#" からなる長さ W の文字列 s_i が与えられます。s_i の j 番目 (1 ≦ j ≦ W) の文字は、"#" の場合にはそのマスに爆弾を設置していることを、"." の場合は設置していないことを表します。
 ・入力は合計で H + 1 行となり、入力値最終行の末尾に改行が 1 つ入ります。
 
 入力例1
 4 4
 #.#.
 ....
 ..#.
 ....
 出力例1
 12
 */

#include "B096.hpp"

class Solution {
public:
    int height, width;
    
    int b096() {
        /**
         * The key of this question is find all the bombs' lines
         * line_h mean horizontal lines
         * line_v mean vertival lines
         */
        vector<int> line_h(height, 0), line_v(width, 0);
        int line_h_number = 0, line_v_number = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                char ch = '.';
                cin >> ch;
                if (ch == '#') {
                    if (line_h[i] == 0) {
                        line_h[i] = 1;
                        line_h_number++;
                    }
                    if (line_v[j] == 0) {
                        line_v[j] = 1;
                        line_v_number++;
                    }
                }
            }
        }
        
        // line_h_number*line_v_number mean reduplicative points
        int result = line_h_number*width + line_v_number*height - line_h_number*line_v_number;
        return result;
    }
};

void testB096() {
    Solution solution = Solution();
    cin >> solution.height >> solution.width;

    cout << solution.b096() << endl;
}
