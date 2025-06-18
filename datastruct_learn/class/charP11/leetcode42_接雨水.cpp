#include"../../STLCOMMON.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        height.push_back(0);
        height.insert(height.begin(),0);
        int N = height.size();
        vector<int>right(N, -1); // 找到右侧第一次大于值的索引, 等于-1 代表右侧没有比它更大的值
        stack<int> stk;
        for(int i = 1; i < N-1 ; i++){
            while(!stk.empty() && height[i] >= height[stk.top()] ){
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        MyPrintOne(right);

        cout << "MyPrintOne " << endl;

        int ans = 0;
        int i =  1;
        for( i = 1; i<= N-2;  ){
            if(height[i] == 0 || right[i] == -1) {
                i++;
                continue;
            }
            int front = i;
            int behind = right[i];
            int total = height[front] * ( behind - front +1);
            int temp = 2 * height[front];
            for(int j = front + 1; j < behind ; j++){
                temp += height[j]; 
            }
            ans += (total -  temp);
            i = behind;
        }


        
        cout << "ans= " << ans << endl;
        return ans;

    }
};

int main()
{
    Solution s1;
    vector<int>nums= {4,2,3};
    int resu = s1.trap(nums);
    cout << "resu = " << resu<< endl;
    return 0;

}