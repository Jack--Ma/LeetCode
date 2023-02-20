//
//  AverageSalaryExcludingTheMinimumAndMaximumSalary .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/2/21.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/?envType=study-plan&id=programming-skills-i
 
 You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

 Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.
 
 Input: salary = [4000,3000,1000,2000]
 Output: 2500.00000
 Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
 Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
 */
extension Solution {
    func AverageSalaryExcludingTheMinimumAndMaximumSalary(_ salary: [Int]) -> Double {
        var sum:Int = 0
        var _min = LONG_MAX, _max = 0
        salary.forEach { (i) in
            sum += i
            _min = min(_min, i)
            _max = max(_max, i)
        }
        // MARK: must transform to Double
        let result = Double(Double(sum-_min-_max) / Double(salary.count-2))
        return result
    }
}
