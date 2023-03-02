//
//  Node.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/1.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

public class Node {
    public var val: Int
    public var children: [Node]
    
    public convenience init(val: Int) {
        self.init(val: val, children: [])
    }
    
    public init(val: Int, children: [Node]) {
        self.val = val
        self.children = children
    }
    
    static let Null = LONG_MAX
}

// root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// tree sample: sample_4_964.png
extension Node {
    
    /// Build A Tree with numbers
    /// - Parameter nums: Int type numbers
    /// - Returns: Root Node
    static func buildTree(_ nums: [Int]) -> Node? {
        if nums.isEmpty {
            return nil
        }
        
        let root = Node(val: Node.Null)
        var currNode = root
        // queue stores all children nodes of currNode.
        var queue: Array<Node> = []
        // currNodes stores all nodes which had traversed.
        // element will be removed when its children nodes had made sure.
        var currNodes: Array<Node> = []

        for num in nums {
            if num == Node.Null {
                // Null means already made sure all children nodes of currNode
                if !queue.isEmpty {
                    // take out all nodes from queue, and append to currNode's children
                    for queueNode in queue {
                        currNode.children.append(queueNode)
                    }
                    // remove queue nodes
                    queue.removeAll()
                }
                // have already set currNode's children nodes.
                // remove from currNodes, and begin loop next node.
                currNode = currNodes.first!
                currNodes.removeFirst()
            } else {
                let node = Node(val: num)
                queue.append(node)
                currNodes.append(node)
            }
        }
        // finally append if queue is not empty
        if !queue.isEmpty {
            for queueNode in queue {
                currNode.children.append(queueNode)
            }
        }
        return root.children.first
    }
    
    /// Print tree by left-->right depth traverse
    func printTree() {
        // currNodes stores all nodes(left to right) in one-level of this tree
        var currNodes: Array<Node> = [self]
        print("\(val) |")
        
        while !currNodes.isEmpty {
            var nextNodes: Array<Node> = []
            
            for node in currNodes {
                // reverse currNode, print its children nodes
                if node.children.isEmpty {
                    // children is empty, use * mark
                    print("* | ", terminator: "")
                } else {
                    // print children nodes
                    node.children.forEach { nextNode in
                        print("\(nextNode.val) ", terminator: "")
                        nextNodes.append(nextNode)
                    }
                    // use | seperate nodes
                    print("| ", terminator: "")
                }
            }
            print("")
            currNodes = nextNodes
        }
        print("")
    }
}

