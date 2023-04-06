#include"../../STLCOMMON.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


int CalMaxSeque(int N, int M ,vector<int>&nums)
{
    MyPrintOne(nums);

    return 0;

}




void GetInputData(int &N, int &M , vector<int>&nums)
{
    nums.clear();
    cin >> N >> M;
    for(int i = 0; i < N ; i++){
        int temp ;
        cin >> temp;
        nums.push_back(temp);
    }
}

int main()
{

    int N =8, M = 3;
    vector<int>nums  = {1 ,3 ,-1, -3 ,5, 3 ,6, 7};
    // GetInputData(N,M,nums); 
    int resu =CalMaxSeque(N,M,nums);
    

    cout << "--end---" << endl;  
    return 0;
}