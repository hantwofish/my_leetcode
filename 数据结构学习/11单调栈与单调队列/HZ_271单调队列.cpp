// #include"../../STLCOMMON.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int>g_minVec;
vector<int>g_maxVec;

int CalQueMinAndMax(int N, int k ,vector<int>&nums)
{
    // 采用滑动窗口
    int i= 0;
    int j = i + k;
    int minNum = *(min_element(nums.begin(), nums.begin()+ k));
    int maxNum = *(max_element(nums.begin(), nums.begin()+ k));
    while( i <=  nums.size() -k ){
        auto itStart = nums.begin()+ i;
        minNum = *(min_element(itStart, itStart+ k));
        maxNum = *(max_element(itStart, itStart+ k));
        // cout << "minNum= " << minNum << " maxNum= "<< maxNum << endl;
        g_minVec.push_back(minNum);
        g_maxVec.push_back(maxNum);
        i++;
    }

    return 0;

}




void GetInputData(int &w, int &n , vector<int>&nums)
{
    nums.clear();
    cin >> w >> n;
    for(int i = 0; i < w ; i++){
        int temp ;
        cin >> temp;
        nums.push_back(temp);
    }
}

int main()
{

    int N =8, K = 3;
    vector<int>nums  = {1 ,3 ,-1, -3 ,5, 3 ,6, 7};
    GetInputData(N,K,nums);
    int resu =CalQueMinAndMax(N,K,nums);
    // cout << resu<< endl;;
    for(int i = 0 ; i< g_minVec.size()-1; i++){
        cout << g_minVec[i] << " ";
    }
    cout << g_minVec[g_minVec.size()-1] << endl;

    for(int i = 0 ; i< g_maxVec.size()-1; i++){
        cout << g_maxVec[i] << " ";
    }
    cout << g_maxVec[g_maxVec.size()-1] << endl;

    // cout << "--end---" << endl;  
    return 0;
}