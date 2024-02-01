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

class Solution{
public:
    int calMaxArray(int& n, vector<int>&nums)
    {
        
        return 0;
    }
};


void getInputData(int& n, vector<vector<int>>&nums)
{
    cin >> n;
    for(int i = 0; i< 8; i++){
        for(int j= 0; j< 8; j++){
            int temp;
            cin >> temp;
            nums[i][j]= temp;
        }
    }
    MyPrintTwo(nums);



    
}

int main()
{
    Solution s1;
    vector<vector<int>>nums(8, vector<int>(8,0));
    int n= 3;
    getInputData(n, nums);

    
    

    cout << "hello" << endl;
    return 0;
}