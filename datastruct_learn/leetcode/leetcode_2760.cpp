#include"../STLCOMMON.h"
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
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int N =nums.size();
        int len = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] % 2 != 0 ){
                continue;
            }
            for(int j = i ; j < nums.size(); j++){
                // 所有值都小于 
                int resu = calLen(nums, i, j, threshold);
                if(resu == -1){
                    continue;
                }else{
                    len = max(len, resu);
                }

            }
        }
        return len;
        
    }
    int calLen(vector<int>& nums, int i, int j, int threshold)
    {
        if(nums[i] > threshold || nums[j] > threshold){
            return -1;
        }
        for(int k = i; k <= j-1; k++){
            if( nums[k] % 2 == nums[k+1]%2){
                return -1;
            }

        }
        return j -i + 1;
    }
};


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    

    cout << "hello" << endl;
    return 0;
}