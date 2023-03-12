//
//  DesignParkingSystem .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/13.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/design-parking-system
 
 Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.

 Implement the ParkingSystem class:

 ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class. The number of slots for each parking space are given as part of the constructor.
 bool addCar(int carType) Checks whether there is a parking space of carType for the car that wants to get into the parking lot. carType can be of three kinds: big, medium, or small, which are represented by 1, 2, and 3 respectively. A car can only park in a parking space of its carType. If there is no space available, return false, else park the car in that size space and return true.
 */

class ParkingSystem {
    var bigCarTotal = 0
    var mediumCarTotal = 0
    var smallCarTotal = 0
    
    var currBig = 0
    var currMedium = 0
    var currSmall = 0
    
    init(_ big: Int, _ medium: Int, _ small: Int) {
        self.bigCarTotal = big
        self.mediumCarTotal = medium
        self.smallCarTotal = small
    }
    
    func addCar(_ carType: Int) -> Bool {
        switch carType {
        case 1:
            self.currBig+=1
            if self.currBig>self.bigCarTotal {
                return false
            }
        case 2:
            self.currMedium+=1
            if self.currMedium>self.mediumCarTotal {
                return false
            }
        case 3:
            self.currSmall+=1
            if self.currSmall>self.smallCarTotal {
                return false
            }
        default:
            return false
        }
        return true
    }
}
