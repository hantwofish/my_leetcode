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

// 前缀和 + 单调队列
class Solution{
public:
    int calMaxArray(int& n, int& M, vector<int>&nums)
    {
        vector<int>sumArray(nums.size(), 0);
        for(int i =0; i < nums.size(); i++){
            if( i== 0){
                sumArray[i] =  + nums[i];
                continue;
            }
            sumArray[i] = sumArray[i-1] + nums[i];
        }
        sumArray.insert(sumArray.begin(),0);
        // MyPrintOne(sumArray);
        // 
        deque<int> myQue;
        myQue.push_back(0);
        int resu =INT32_MIN;
        for(int i = 1 ; i < sumArray.size(); i++){
            resu = max(resu, sumArray[i] - sumArray[myQue.front()]);

            // 先出队
            // if(i > M){
            //     if( myQue.front() == i - M) myQue.pop_front();
            // }

            // 维护一个优先队列
            int temp = sumArray[i];
            while(!myQue.empty() && temp < sumArray[myQue.back()]){
                myQue.pop_back();
            }
            myQue.push_back(i);
            if( myQue.front() == i - M) myQue.pop_front();
            
        }
        // cout << "resu= " << resu << endl;

        return resu;
    }
};


void getInputData(int& n, int& M, vector<int>&nums)
{
    cin >> n >> M;
    nums.clear();
    for(int i =0; i< n; i++){
        int temp = 0;
        cin >> temp;
        nums.push_back(temp);
    }
    // MyPrintOne(nums);

}

int main()
{
    Solution s1;
    int n = 6;
    int m = 4;
    vector<int>nums = {1, -3 ,5 ,1 ,-2, 4};
    getInputData(n,m, nums);
    int resu = s1.calMaxArray(n,m,nums);
    

    cout << resu << endl;
    return 0;
}