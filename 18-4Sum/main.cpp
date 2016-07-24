//
//  main.cpp
//  18-4Sum
//
//  Created by JackMa on 16/7/24.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//vector<vector<int>> fourSum(vector<int> &nums, int target) {
//    vector<vector<int>> results = {};
//    //少于4个，直接返回空
//    if (nums.size() < 4) {
//        return results;
//    }
//    sort(nums.begin(), nums.end());
//    
//    for (int i = 0; i < nums.size(); i++) {
//        //避免重复
//        if (i > 0 && nums[i] == nums[i-1]) {
//            continue;
//        }
//        for (int j = i+1; j < nums.size(); j++) {
//            //避免重复
//            if (j > i+1 && nums[j] == nums[j-1]) {
//                continue;
//            }
//            
//            int start = j+1, end = int(nums.size())-1;
//            int num_to_target = target-nums[i]-nums[j];
//            
//            while (start < end) {
//                //避免重复
//                if (start > j+1 && nums[start] == nums[start-1]) {
//                    start++;
//                    continue;
//                }
//                //三种情况的处理
//                if (num_to_target > nums[start]+nums[end]) {
//                    start++;
//                } else if (num_to_target < nums[start]+nums[end]) {
//                    end--;
//                } else {
//                    vector<int> result = {nums[i],nums[j],nums[start],nums[end]};
//                    results.push_back(result);
//
//                    start++;
//                }
//            }
//        }
//    }
//    
//    return results;
//}

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> results = {};
    //少于4个，直接返回空
    if (nums.size() < 4) {
        return results;
    }
    sort(nums.begin(), nums.end());
    
    //缓存计算任意两个数的和的multimap
    unordered_multimap<int, pair<int, int>> map;
    for (int i = 0; i < nums.size()-1; i++) {
        for (int j = i+1; j < nums.size(); j++) {
            map.insert(make_pair(nums[i]+nums[j], make_pair(i, j)));
        }
    }
    
    //任取map中一个pair对'i'，计算map中有没有与之匹配的pair对'j'
    //这会产生的问题是，四个数的求和会产生四个相同的result
    for (auto i = map.begin(); i != map.end(); i++) {
        int num_to_target = target - i->first;
        //equal.range方法：返回一对迭代器i和j
        //其中i是在不破坏次序的前提下，value可插入的第一个位置（亦即lower_bound）
        //j则是在不破坏次序的前提下，value可插入的最后一个位置（亦即upper_bound）
        auto range = map.equal_range(num_to_target);
        
        for (auto j = range.first; j != range.second; j++) {
            int a = i->second.first;
            int b = i->second.second;
            int c = j->second.first;
            int d = j->second.second;
            if (a != c && a != d && b != c && b != d) {
                vector<int> result = {nums[a],nums[b],nums[c],nums[d]};
                sort(result.begin(), result.end());
                results.push_back(result);
            }
            
        }
    }
    
    sort(results.begin(), results.end());
    /**
     unique函数作用是去除vector的重复项，只是将重复的部分放到vector的最后，并没有改变vector的大小
     返回的是一个迭代器，指向新的终点，即重复结点的第一个位置
     **/
    auto new_end = unique(results.begin(), results.end());
    //删除new_end之后的重复结点
    results.erase(new_end, results.end());
    return results;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
    int target = -236727523;
    vector<vector<int>> results = fourSum(nums, target);
    
    return 0;
}
