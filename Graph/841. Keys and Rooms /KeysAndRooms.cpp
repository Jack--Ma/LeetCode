//
//  KeysAndRooms.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/29.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "KeysAndRooms.hpp"

/**
 There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
 
 When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
 
 Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.
 
 Input: rooms = [[1],[2],[3],[]]
 Output: true
 Explanation:
 We visit room 0 and pick up key 1.
 We then visit room 1 and pick up key 2.
 We then visit room 2 and pick up key 3.
 We then visit room 3.
 Since we were able to visit every room, we return true.
 
 Input: rooms = [[1,3],[3,0,1],[2],[0]]
 Output: false
 Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
 */

void testCanVisitAllRooms() {
    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    rooms = {{1},{2},{3},{}};
    cout << Solution().canVisitAllRooms(rooms) << endl;
}

/// Best solution by use recursion
/// @param rooms rooms original info
/// @param roomID ID of the room we can open
/// @param visit room visit info
static inline void _canVisitAllRooms(vector<vector<int>>& rooms, int roomID, vector<int> &visit) {
    vector<int> room = rooms[roomID];
    
    for (int id: room) {
        // visit this room if hasn't been opened
        if (visit[id] == 0) {
            visit[id] = 1;
            _canVisitAllRooms(rooms, id, visit);
        }
    }
}

bool Solution::canVisitAllRooms(vector<vector<int>>& rooms) {
    // index mean 0~n-1 room, value mean this room can be opened or not
    vector<int> visit(rooms.size(), 0);
    // default room 0 be opened
    visit[0] = 1;
    
    _canVisitAllRooms(rooms, 0, visit);
    
    // all rooms must be opened
    for (int _ : visit) {
        if (!_) {
            return false;
        }
    }
    
    return true;
}
