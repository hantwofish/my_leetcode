// #include"../../STLCOMMON.h"
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

using namespace std;

class Solution {

public:
    int MinOpeRateTimes(int N, int A, int B, vector<int>&nums)
    {
        HEIGHT = N;
        SRC = A;
        DST = B;
        resu = INT32_MAX;
        // info = nums;
        nums.insert(nums.begin(),0);
        // MyPrintOne(nums);
        

        int opeRateTimes = 0;
        DFS(1, opeRateTimes,nums);
        int minNum = -1;
        if(resu == INT32_MAX){
            return -1;
        }


 

        return resu;

    }
    void  DFS(int curLocation, int &opeRateTimes,vector<int>&nums)
    {
        // cout << "DFS curLocation= "<< curLocation << " opeRateTimes= " << opeRateTimes << endl;
        if(curLocation == DST){
            // cout << "curLocation == DST opeRateTimes= " << opeRateTimes << endl;
            resu = min(resu, opeRateTimes);
            return;
        }

        // 选择向上

        int upLocation = curLocation + nums[curLocation];
        bool flag = (find(isUsesd.begin(), isUsesd.end(), upLocation) == isUsesd.end());
        if(upLocation > 0 &&  upLocation <= HEIGHT && flag){
            opeRateTimes++;
            isUsesd.push_back(upLocation);
            DFS(curLocation + nums[curLocation], opeRateTimes,nums);
            opeRateTimes--;
            isUsesd.pop_back();
        }
        // 向下走
        int downLocation = curLocation - nums[curLocation];
        flag = (find(isUsesd.begin(), isUsesd.end(), downLocation) == isUsesd.end());
        if(downLocation > 0 &&  downLocation <= HEIGHT && flag){
            opeRateTimes++;
            isUsesd.push_back(downLocation);
            DFS(curLocation - nums[curLocation], opeRateTimes, nums);
            opeRateTimes--;
            isUsesd.pop_back();
        }
        
        
    }
public:
    int SRC;
    int DST;
    int HEIGHT;
    int resu;
    vector<int> isUsesd;// 当前楼层是否已经走过


};


void GetNum(int &N, int &A, int &B, vector<int>&nums)
{
    cin >> N >> A >> B;
    nums.clear();
    for(int i = 0 ; i< N;i++){
        int temp ;
        cin >> temp;
        nums.push_back(temp);
    }
}

int main()
{
    int N =6;
    int src =1, dst = 3;
    vector<int>nums = {3,3,1,2,5,2};
    GetNum(N,src,dst,nums);
    Solution s1;
    int resu = s1.MinOpeRateTimes(N,src,dst, nums);

    cout  << resu << endl;
    // cout << "---end----" << endl;
    return 0;
}