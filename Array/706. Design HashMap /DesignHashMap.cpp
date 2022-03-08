//
//  DesignHashMap.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/8.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <list>
#include "DesignHashMap.hpp"

/**
 Design a HashMap without using any built-in hash table libraries.

 Input
 ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
 [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
 Output
 [null, null, null, 1, -1, null, 1, null, -1]
 */

/// Initializes the object with an empty map.
MyHashMap::MyHashMap() {
    hash.resize(hashCount);
}

/// Inserts a (key, value) pair into the HashMap.
/// If the key already exists in the map, update the corresponding value.
void MyHashMap::put(int key, int value) {
    list<pair<int, int>> &keyList = hash[_hashFunction(key)];
    for (auto &pair : keyList) {
        if (pair.first == key) {
            pair.second = value;
            return;
        }
    }
    keyList.emplace_back(make_pair(key, value));
}

/// Returns the value to which the specified key is mapped,
/// or -1 if this map contains no mapping for the key.
int MyHashMap::get(int key) {
    list<pair<int, int>> keyList = hash[_hashFunction(key)];
    for (auto pair : keyList) {
        if (pair.first == key) {
            return pair.second;
        }
    }
    return -1;
}

/// Removes the key and its corresponding value if the map contains the mapping for the key.
void MyHashMap::remove(int key) {
    list<pair<int, int>> &keyList = hash[_hashFunction(key)];
    for (auto &pair : keyList) {
        if (pair.first == key) {
            keyList.remove(pair);
            return;
        }
    }
}

int MyHashMap::_hashFunction(int key) {
    return key % hashCount;
}

void testMyHashMap() {
    MyHashMap *obj = new MyHashMap();
    obj->put(1, 1);
    obj->get(1);
    obj->remove(1);
}
