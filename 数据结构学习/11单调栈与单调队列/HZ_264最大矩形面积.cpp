// #include"../../STLCOMMON.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;


long long CalMaxSeque(long long M ,vector<long long>&nums)
{
    nums.push_back(-1);
    nums.insert(nums.begin(),-1);
    // MyPrlong longOne(nums);
    long long N =nums.size(); 


    // 以每个值作为矩形最低的值，利用单调栈找到两边低于当前值的索引下标
    vector<long long> left(N,0);
    vector<long long> right(N,N-1);
    stack<long long>stk; // 记录索引
    for(long long i = 1; i <=  N-2; i++){
        while(!stk.empty() && nums[i] < nums[stk.top()]){
            right[stk.top()] = i;
            stk.pop();
        }
        
        stk.push(i);
    }
    // MyPrlong longOne(right);
    while(!stk.empty()) stk.pop();
    // 左面比它小的元素
    for(long long i = N-2; i >=  1; i--){
        while(!stk.empty() && nums[i] < nums[stk.top()]){
            left[stk.top()] = i;
            stk.pop();
        }
        
        stk.push(i);
    }
    // MyPrlong longOne(left);
    long long ans = 0;
    for(long long i = 1; i <= N-1; i++){
        long long height = right[i] - left[i] -1;
        ans = max(ans, nums[i] * height);
    }


    return ans;

}




void GetInputData(long long &N,  vector<long long>&nums)
{
    nums.clear();
    cin >> N ;
    for(long long i = 0; i < N ; i++){
        long long temp ;
        cin >> temp;
        nums.push_back(temp);
    }
}

int main()
{

    long long N =7;
    vector<long long>nums  = {2, 1 ,4,5, 1, 3, 3};
    GetInputData(N,nums); 
    long long resu =CalMaxSeque(N,nums);
    

    cout << resu << endl;  
    return 0;
}