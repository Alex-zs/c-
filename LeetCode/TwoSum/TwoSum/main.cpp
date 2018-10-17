//
//  main.cpp
//  TwoSum
//
//  Created by alex on 2018/10/15.
//  Copyright © 2018 alex. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoNum(vector<int>& nums, int target) {
    vector<int> result;
    for(int i = 0; i< nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] + nums[j] == target){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {2, 7, 11, 15};
    vector<int> result = twoNum(nums, 9);
    cout << result[0] << endl;
    cout << result[1] << endl;
}
