// #include"../STLCOMMON.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<set>
#include<unordered_set>

#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<deque>
#include <iterator>
using namespace std;
class Solution {
public:
    int lastRemaining(int n) {
        vector<int>nums;
        for(int i= 1; i <= n ; i++){
            nums.push_back(i);
        }
        MyPrintOne(nums);
        while(nums.size() > 1) {
            for(int i = 0; i < nums.size() ; i = i+2){
                nums[i] = 0;
            }
            RemoveVecEle(nums,0);
            MyPrintOne(nums);
            cout << "nums size= " << nums.size() << endl;
            if(nums.size()==1){
                break;
            }
            for(int i = nums.size()-1; i >= 0; i = i-2){
                if(i < 0){
                    continue;
                }
                nums[i] = 0;
            }
            RemoveVecEle(nums,0);
            cout << "   nums size= " << nums.size() << endl;
            MyPrintOne(nums);
        }
        return nums[0];
    }
};

int main()
{
    Solution s1;
    int resu =s1.lastRemaining(4095);
    cout << "resu= " << resu << endl;
    return 0;
}