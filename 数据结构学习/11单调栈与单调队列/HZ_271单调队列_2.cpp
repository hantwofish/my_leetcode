// #include"../../STLCOMMON.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<deque>

using namespace std;

vector<int>g_minVec;
vector<int>g_maxVec;

int CalQueMinAndMax(int N, int k ,vector<int>&nums)
{
    // 使用单调队列来实现
    deque<int> deqe; // 压入数组中索引
    for(int i = 0; i < nums.size(); i++){
        while((!deqe.empty() && (nums[deqe.back()] > nums[i]))){
            deqe.pop_back();
        }
        deqe.push_back(i);

        if(i - deqe.front() == k){
            // cout << " pop front "<< "i= " << i << "  deqe.front()=  " << deqe.front() << " value= " << nums[deqe.front()] << endl;
            deqe.pop_front();
        }
        if(i +1 < k) continue;
        if(i >= k ) cout << " ";
        cout<< nums[deqe.front()];
        

    }
    cout << endl;

    deqe.clear();
    for(int i = 0; i < nums.size(); i++){
        while((!deqe.empty() && (nums[deqe.back()] < nums[i]))){
            deqe.pop_back();
        }
        deqe.push_back(i);

        if(i - deqe.front() == k){
            // cout << " pop front "<< "i= " << i << "  deqe.front()=  " << deqe.front() << " value= " << nums[deqe.front()] << endl;
            deqe.pop_front();
        }
        if(i +1 < k) continue;
        if(i >= k ) cout << " ";
        cout<< nums[deqe.front()];
        

    }
    cout << endl;
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
    vector<int>nums  = {4,1,3,0,5,9,2};
    GetInputData(N,K,nums);
    int resu =CalQueMinAndMax(nums.size(),K,nums);
    // cout << resu<< endl;;


    // cout << "--end---" << endl;  
    return 0;
}