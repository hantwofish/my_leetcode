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

int CalQueMinAndMax(int limitWeight, int n ,vector<int>&nums)
{
    sort(nums.begin(), nums.end());
    int i  = 0, j = nums.size()-1, cnt = 0;
    while(i < j){
        if(nums[i] + nums[j] <= limitWeight){
            i++;
            j--;
        }else{
            j--;
        }
        cnt++;
    }
    if(i == j){
        cnt++;
    }

    return cnt;
}

void GetInputData(int &w, int &n , vector<int>&nums)
{
    nums.clear();
    cin >> w >> n;
    for(int i = 0; i < n ; i++){
        int temp ;
        cin >> temp;
        nums.push_back(temp);
    }
}

int main()
{

    int w =100, n = 9;
    vector<int>nums  = {90, 20, 20, 30, 50, 60, 70, 80, 90};
    GetInputData(w,n,nums);
    int resu =CalQueMinAndMax(w, n, nums);
    cout << resu<< endl;


    // cout << "--end---" << endl;  
    return 0;
}