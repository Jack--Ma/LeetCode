//
//  Helper.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/7.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef Helper_hpp
#define Helper_hpp

#include <stdio.h>

template <typename T>
std::ostream& operator<<(std::ostream& output, std::vector<T> const& values) {
    for (auto const& value : values) {
        output << value << " ";
    }
    output << endl;
    return output;
}

template <typename T>
void printVector(vector<T> const& v) {
    for (auto const& i: v) {
        cout << i << " ";
    }
    cout << endl;
}

template <typename T>
void printVector(vector<vector<T>> const& v) {
    for (vector<T> const& i : v) {
        printVector(i);
    }
}

template <class _Tp, class _Map>
inline vector<_Tp> vector_map(vector<_Tp> __first, _Map __map) {
    vector<_Tp> __result;
    for (_Tp _i : __first) {
        __result.push_back(__map(_i));
    }
    return __result;
}

/// split string to array
vector<string> string_split(const string &str, const string &pattern);

#endif /* Helper_hpp */
