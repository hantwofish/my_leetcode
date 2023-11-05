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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        numTemp = nums;
        deque<int>myQue; // 单调队列，维持一个双端队列
        vector<int>resu;

        for(int i =0; i< nums.size(); i++){
            int tempValue = nums[i];
            // 判断队首是否需要出队
            if( i>= k -1){
                int deleIndex = i - k;
                if( myQue.front() == deleIndex){
                    myQue.pop_front();
                }
            }


            // 维持队列的单调性
            if( myQue.empty() ){
                myQue.push_back(i);
            }else{
                // 维持单调性
                while(!myQue.empty() && nums[myQue.back()] < tempValue){
                    myQue.pop_back();
                }
                myQue.push_back(i);
            }
            if( i>= k -1){
                cout << "i= " << i << " max= " << nums[myQue.front()] << endl;
                resu.push_back(nums[myQue.front()]);
            }
            PrintQue(myQue);
        }
        return resu;
    }
    void PrintQue(deque<int>&myQue)
    {
        auto it = myQue.begin();
        while(it != myQue.end()){
            cout << numTemp[*it] << " ";
            it++;
        }
        cout << endl;

    }
public:
    vector<int>numTemp;
};


void getInputData(int& n, vector<int>&nums)
{

    
}

int main()
{
    Solution s1;
    vector<int>nums = {1};
    int k =1;
    vector<int>resu = s1.maxSlidingWindow(nums,k);
    MyPrintOne(resu);
    

    cout << "hello" << endl;
    return 0;
}