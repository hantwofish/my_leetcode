#ifndef COMMON_ALO
#define COMMON_ALO

#include"./STLCOMMON.h"

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
// 此只要我们向左👈找到第一个比A[i]小的数A[left]以及向右👉找到第一个比E小的数A[right]，就可以确定E的辐射范围为A[left+1:right]。这就叫做下一个更小/更大的数问题。解决这类问题的通用解法即为单调栈。

// 作者：超小白
// 链接：https://leetcode.cn/problems/sum-of-subarray-minimums/submissions/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class sigStack{
public:
    void calNeiMin(vector<int>&nums){
        int N =nums.size();
        leftArry.resize(N,-1);
        rightArry.resize(N,N);
        // 计算右面第一个小于当前元素的位置，记录索引
        stack<int>rightStak;
        for(int i = 0; i <N; i++){
            if(rightStak.empty()) {
                rightStak.push(i);
                continue;
            }
            int tempval = nums[i];
            // cout << "top= " << nums[rightStak.top()] << " tempvla= " << tempval << endl;
            while((!rightStak.empty()) &&  (tempval < nums[rightStak.top()])){
                
                rightArry[rightStak.top()] = i;
                rightStak.pop();
            }
            rightStak.push(i);
        }
        MyPrintOne(rightArry);

        // 计算左面第一个小于的位置
        stack<int>leftstack;
        for(int i = N-1; i >= 0; i--){
            if(leftstack.empty()) {
                leftstack.push(i);
                continue;
            }
            int tempval = nums[i];
            // cout << "top= " << nums[leftstack.top()] << " tempvla= " << tempval << endl;
            while((!leftstack.empty()) &&  (tempval < nums[leftstack.top()])){
                
                leftArry[leftstack.top()] = i;
                leftstack.pop();
            }
            leftstack.push(i);
        }
        MyPrintOne(leftArry);
        

    }


public:
    vector<int>leftArry;
    vector<int>rightArry;

};

#endif