//
//  DesignHashMap.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/8.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef DesignHashMap_hpp
#define DesignHashMap_hpp

#include <list>
#include <stdio.h>

// https://leetcode.com/problems/design-hashmap/
class MyHashMap {
private:
    const int hashCount = 10000;
    vector<list<pair<int, int>>> hash;
    
    int _hashFunction(int kay);
    
public:
    MyHashMap();
    
    void put(int key, int value);
    
    int get(int key);
    
    void remove(int key);
};

void testMyHashMap();

#endif /* DesignHashMap_hpp */
