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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int digSpace) {
        // int digSpace = k;
        frontSum.resize(nums.size()+1,0);
        for(int i = 1;i< frontSum.size();i++ ){
            frontSum[i] = frontSum[i-1] +  nums[i-1];
        }
        MyPrintOne(frontSum);
        



        cout << "size= " << nums.size() << endl;
        vector<int>resu(3,0);
        int tempSum =0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+ digSpace; j < nums.size();j++){
                for(int k = j + digSpace; k < nums.size();k++){
                    if(k + digSpace -1 >= nums.size()){
                        break;
                    }
                    
                    int a = calSum(nums,digSpace , i);
                    int b = calSum(nums,digSpace , j);
                    int c = calSum(nums,digSpace , k);
                    cout << "i = " << i << " j= " << j << " k= " << k << " sum= " << (a+b +c)<< endl;
                    if( a + b + c > tempSum ){
                        resu[0]= i; resu[1]= j; resu[2]= k;
                        tempSum = a + b + c;
                    }
                    
                }
            }
        }
        return resu;
    }
    int calSum2(vector<int>& nums, int digSpace, int start)
    {
        int resu = 0;
        int end = start + digSpace - 1;
        for(int i=start; i <= end; i++){
            resu += nums[i];
        }
        cout << "calSum resu= " << resu << " frontSum= " << (frontSum[end + 1] - frontSum[start]) << endl;
        return resu;
    }
    int calSum(vector<int>& nums, int digSpace, int start)
    {
        // int resu = 0;
        int end = start + digSpace - 1;
        // for(int i=start; i <= end; i++){
        //     resu += nums[i];
        // }
        // cout << "calSum resu= " << resu << " frontSum= " << (frontSum[end + 1] - frontSum[start]) << endl;
        return (frontSum[end + 1] - frontSum[start]);
    }
public:
    vector<int>frontSum;
};


int main()
{
    Solution s1;
    vector<int>nums = {1,3,4,7, 8,0,5};
    int k = 2;
    vector<int>resu = s1.maxSumOfThreeSubarrays(nums ,k) ;
    MyPrintOne(resu);
    cout << "hello" << endl;
    return 0;
}