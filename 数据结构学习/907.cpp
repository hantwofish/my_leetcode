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
    int sumSubarrayMins(vector<int>& arr) {
        int resu = 0;
        int N = arr.size();
        sort(arr.begin(),arr.end());
        for(int i =0 ; i < N; i++){
            resu += arr[i] * (N - i);
            resu = resu % nummod;
        }

        return resu;
    }
public:
    const  int nummod = pow(10,9)+ 7; 
};




int main()
{
    Solution s1;
    vector<int>nums= {1,2,3,4};
    int resu = s1.sumSubarrayMins(nums);
    cout << "resu= " << resu << endl;
    

    cout << "hello" << endl;
    return 0;
}