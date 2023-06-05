//
//  Company1Code.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/6/4.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

extension Solution {
    private func solution6_traverse(_ i: Int, _ j: Int, _ result: Int, _ value: Int, _ mat: [[Int]], _ flagMap: inout [[Int]]) {
        let height = mat.count, width = mat[0].count
        // Out-of-bound check
        guard i >= 0, i < height, j >= 0, j < width else {
            return
        }
        // Number not equal check
        guard value == mat[i][j] else {
            return
        }
        // Prevent duplicate checks
        guard flagMap[i][j] == 0 else {
            return
        }
        // [i][j] is marked with number [result]
        flagMap[i][j] = result
        // left
        solution6_traverse(i, j-1, result, value, mat, &flagMap)
        // up
        solution6_traverse(i-1, j, result, value, mat, &flagMap)
        // right
        solution6_traverse(i, j+1, result, value, mat, &flagMap)
        // down
        solution6_traverse(i+1, j, result, value, mat, &flagMap)
    }
    
    public func solution6(_ mat: inout [[Int]]) -> Int {
        // Implement your solution here
        var result = 0
        let height = mat.count, width = mat[0].count
        var flagMap = Array(repeating: Array(repeating: 0, count: width), count: height)
        
        for (i, nums) in mat.enumerated() {
            for (j, num) in nums.enumerated() {
                guard flagMap[i][j] == 0 else {
                    // flag not 0 mean this number had been used
                    continue
                }
                // result means mat[i][j] country number
                result += 1
                solution6_traverse(i, j, result, num, mat, &flagMap)
            }
        }
        
        return result
    }
    
    public func solution5(_ nums : inout [Int]) -> Int {
        // Implement your solution here
        var maxLength = 1
        
        nums = nums.sorted(by: >)
        for (i, num) in nums.enumerated() {
            // calculate every sub array from i
            var length = 1
            var j = i+1
            while j < nums.count {
                let numJ = nums[j]
                // diff equal to or less than 1
                guard num - numJ <= 1 else {
                    break
                }
                length += 1
                j+=1
            }
            maxLength = max(maxLength, length)
        }
        
        return maxLength
    }
    
    public func solution4(_ N : Int) -> Int {
        guard N >= 10 else {
            return 1
        }
        var result = 1
        
        let nums = String(N).compactMap({ Int(String($0)) })
        var repeatArray = Array(repeating: 0, count: 10)
        for num in nums {
            repeatArray[num]+=1
        }
        let zeroCount = repeatArray[0]
        // calculate all numbers(no 0, no repeat) result
        var i = nums.count
        while i > 0 {
            result *= i
            i-=1
        }
        // remove 0 prefix number
        result -= (zeroCount * result / nums.count)
        // remove repeat number
        for count in repeatArray {
            if count > 1 {
                // include repeat number
                var i = count, r = 1
                while i > 0 {
                    r *= i
                    i-=1
                }
                result /= r
            }
        }
        
        return result
    }
    
    public func solution2(_ nums : inout [Int]) -> Int {
        var result = -1
        guard nums.count >= 3 else {
            return result
        }
        
        nums = nums.sorted(by: >)
        var a = 0, b = 1, c = 2
        while c < nums.count {
            let numA = nums[a], numB = nums[b], numC = nums[c]
            if (numA+numB > numC) && (numA+numC > numB) && (numB+numC > numA) {
                result = numA+numB+numC
                break
            }
            a+=1; b+=1; c+=1
        }
        
        return result
    }
    
    public func solution1(_ nums : inout [Int]) -> Int {
        // Implement your solution here
        var result = 1
        
        var i = 0
        while i < nums.count {
            result+=1
            guard i >= 0 else {
                break
            }
            let num = nums[i]
            guard num >= 0 else {
                result+=1
                break
            }
            i = nums[num]
        }
        
        return result
    }
}
