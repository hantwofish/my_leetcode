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

bool cmp(int x,int y)
{    
    return x > y;
}



class Solution {
public:
    int maximumSum(vector<int>& nums) {
        for(int i = 0; i< nums.size(); i++){
            
            int val = calNumVal(nums[i]);
            myMap[val].push_back(nums[i]);
        }
        int resu = -1;
        for(auto it = myMap.begin(); it != myMap.end(); it++){
            if(it->second.size() < 2){
                continue;
            }
            vector<int>temp = it->second;
            sort(temp.begin(),temp.end(),cmp);
            resu = max(resu, temp[0]+temp[1]);
        }
        return resu;
        
    }
    int calNumVal(int a)
    {
        string str = to_string(a);
        int num = 0;
        for (int i = 0; i < str.size(); i++) {
            num += (str[i] - '0');
        }
        return num;
    }

public:
    unordered_map<int, vector<int>>myMap;
};


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    vector<int>nums = {12,34,7,3};
    cout << s1.maximumSum(nums) << endl;
    

    cout << "hello" << endl;
    return 0;
}