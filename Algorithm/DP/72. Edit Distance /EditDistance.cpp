//
//  EditDistance.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/8.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "EditDistance.hpp"

/**
 Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
 
 You have the following three operations permitted on a word:
    * Insert a character
    * Delete a character
    * Replace a character
 
 Input: word1 = "horse", word2 = "ros"
 Output: 3
 Explanation:
 horse -> rorse (replace 'h' with 'r')
 rorse -> rose (remove 'r')
 rose -> ros (remove 'e')
 
 Input: word1 = "intention", word2 = "execution"
 Output: 5
 Explanation:
 intention -> inention (remove 't')
 inention -> enention (replace 'i' with 'e')
 enention -> exention (replace 'n' with 'x')
 exention -> exection (replace 'n' with 'c')
 exection -> execution (insert 'u')
 */

void testEditDistance() {
    cout << Solution().editDistance("intention", "execution") << endl;
}

// Solution by use DP
int _editDistance_DP(string word1, string word2) {
    const int L1 = (int)word1.length();
    const int L2 = (int)word2.length();
    
    vector<vector<int>> DP(L1+1, vector<int>(L2+1, 0));
    
    // first column
    for (int i = 0; i <= L1; i++) {
        DP[i][0] = i;
    }
    // first row
    for (int j = 0; j <= L2; j++) {
        DP[0][j] = j;
    }
    
    /**
     Eg word1="ros", word2="horse", now the DP is:
         h o r s e
       0 1 2 3 4 5
     r 1
     o 2
     s 3
     
     * DP[0][3]=3 mean the minimum number of operations covert string "" to string "hor", so we need to insert three times.
     * DP[i][j] mean the minimum number of operations convert string word1[0,i-1] to string word2[0,j-1].
     
     So we need to find the value of DP[L1][L2]
     
     Three operations:
     1. insert: DP[i][j] = 1+DP[i][j-1]
     2. delete: DP[i][j] = 1+DP[i-1][j]
     3. replace: DP[i][j] = 1+DP[i-1][j-1]
     
     Finally the DP is:
         h o r s e
       0 1 2 3 4 5
     r 1 1 2 3 4 5
     o 2 2 1 2 3 4
     s 3 3 2 2 2 3
     
     So the minimum number of operations is 3
     */
    
    for (int i = 1; i <= L1; i++) {
        for (int j = 1; j <= L2; j++) {
            if (word1[i-1] == word2[j-1]) {
                // same char, no need to deal
                DP[i][j] = DP[i-1][j-1];
            } else {
                int insertCount = 1+DP[i][j-1];
                int deleteCount = 1+DP[i-1][j];
                int replaceCount = 1+DP[i-1][j-1];
                
                DP[i][j] = min({insertCount, deleteCount, replaceCount});
            }
        }
    }
    
    return DP[L1][L2];
}

int Solution::editDistance(string word1, string word2) {
    return _editDistance_DP(word1, word2);
}
