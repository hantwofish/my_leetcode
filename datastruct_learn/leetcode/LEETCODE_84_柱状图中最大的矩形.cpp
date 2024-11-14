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
// 遍历每个柱子的高度，寻找左侧，右侧，小于高度的位置


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==1){
            return heights[0];
        }

        heights.insert(heights.begin(), -1);
        heights.push_back(-1);
        MyPrintOne(heights);
        leftMin.resize(heights.size(), 0);
        rightMIn.resize(heights.size(), 0);

        stack<int>myStack;
        // 寻找右面小于当前的位置
        for(int i = 0; i < heights.size(); i++  ){
            while(!myStack.empty() &&  heights[i] < heights[myStack.top()]){
                rightMIn[myStack.top()] = i;
                myStack.pop();
                
            }
            myStack.push(i);
        }

        while (!myStack.empty()) {
            myStack.pop();
        }
        
        // 寻找左面小于当前的位置
        for(int i = heights.size() -1; i >= 0; i--){
            while(!myStack.empty() &&  heights[i] < heights[myStack.top()]){
                leftMin[myStack.top()] = i;
                myStack.pop();
                
            }
            myStack.push(i);
        }

        for(int i =0; i< heights.size(); i++){
            printf(" heights[%d]=%3d  left heights[%d]=%3d right heights[%d]=%3d \n",
                i, heights[i], leftMin[i], heights[leftMin[i]], rightMIn[i], heights[rightMIn[i]]);
        }
        int resu = 0;
        for(int i = 1; i< heights.size() -1; i++){
            int left = leftMin[i];
            int right = rightMIn[i];
            left = (heights[leftMin[i]] == -1) ? 1  : leftMin[i] + 1;
            right = (heights[rightMIn[i]] == -1) ? heights.size() -2 : rightMIn[i] -1;
            cout << "i= " << i  << " height= " << heights[i] 
            << " left= " << left << " right= " << right << endl;

            int temp = heights[i] * (right - left + 1);
            resu = max(resu, temp);
        }




        return resu;
    }
public:
    vector<int>leftMin;
    vector<int>rightMIn;
};


int main()
{
    Solution s1;
    vector<int>heights  = {1,1};
    int resu = s1.largestRectangleArea(heights);
    cout << "resu= " << resu << endl;


    cout << "hello" << endl;
    return 0;
}