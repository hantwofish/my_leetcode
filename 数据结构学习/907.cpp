#include"../STLCOMMON.h"
#include"../COMMONALO.h"
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
        sigStack st;
        st.calNeiMin(arr);
        leftminArr = st.leftArry;
        rightminArr = st.rightArry;
        int leftwidth =0;
        for(int i =0 ; i <N; i++){
            int leftbond = leftminArr[i];
            int rightbond = rightminArr[i];
             leftwidth = i - (leftbond+1);
            if(leftbond == -1){
                leftwidth = 1;
            }       
            int rightwidth = (rightbond-1) -i;
            if(rightbond == N){
                rightwidth = 1;
            }
            
            int temp = arr[i] * (leftwidth * rightwidth);
            if(resu + temp > nummod){
                resu = (resu+ temp - nummod);
            }else {
                resu = resu + temp;
            }
            
        }


        return resu;
    }
public:
    const  int nummod = pow(10,9)+ 7; 
    vector<int>leftminArr;
    vector<int>rightminArr;
};




int main()
{
    Solution s1;
    int resu = 0;
    vector<int>nums= {3,1,2,4};
     resu = s1.sumSubarrayMins(nums);
    cout << "resu34= " << resu << endl;
    

    cout << "hello" << endl;
    return 0;
}