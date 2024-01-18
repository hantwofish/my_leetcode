#include"../../STLCOMMON.h"
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
using namespace std;


class Solution{
public:
    void calResu(vector<vector<int>>&nums)
    {
        // MyPrintTwo(nums);
        // cout << "--------" << endl;
        int M = nums[0].size();
        int N = nums.size();
        sort(nums.begin(),nums.end());
        // MyPrintTwo(nums);
        // cout << "--------" << endl;

        for(int i = 0 ; i < nums.size();i++){
            sort(nums[i].begin(),nums[i].end());
        }
        // MyPrintTwo(nums);
        // cout << "--------" << endl;       
        



        
        int tmp = 0;
        for(int  i = 0; i < nums.size()-1;i++){
            tmp +=  nums[i][0];
        }
        for(int i = 0; i < M;i++){
            resu.push_back(tmp + nums[N-1][i]);
        }
        PrintVec();
       
       return ;
    }
    void PrintVec()
    {
        for(int i = 0; i < resu.size()-1;i++){
            cout << resu[i] << " ";
        }
        cout << resu[resu.size()-1];
    }

public:
    vector<int>resu ;
};


void ReceiveData(int N, int M, vector<vector<int>>&nums)
{
    cin >> N >>M;
    nums.clear();
    nums.resize(N,vector<int>(M,0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j <M; j++){
            int temp1;
            cin >> temp1;
            nums[i][j] = temp1;
        }
    }

}
int main()
{
    Solution s1;
    int N = 2;
    int M = 3;
    vector<vector<int>>nums = {
        {1,1,3},
        {2,2,3}
    };
    ReceiveData(N,M,nums);
     s1.calResu(nums);
   

    return 0;

}