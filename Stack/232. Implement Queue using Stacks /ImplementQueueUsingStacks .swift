//
//  ImplementQueueUsingStacks .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/12.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/implement-queue-using-stacks
 
 Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
 */

class MyQueue {
    var stack: Array<Int>
    
    init() {
        stack = [Int]()
    }
    
    func push(_ x: Int) {
        stack.insert(x, at: 0)
    }
    
    func pop() -> Int {
        guard let pop = stack.last else { return 0 }
        stack.removeLast()
        return pop
    }
    
    func peek() -> Int {
        guard let pop = stack.last else { return 0 }
        return pop
    }
    
    func empty() -> Bool {
        return stack.count == 0
    }
}
