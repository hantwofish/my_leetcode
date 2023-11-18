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

class NumArray {
public:
    NumArray(vector<int>& nums) {
        array = nums;
        array.insert(array.begin(), 0);
        sumBefor.resize(nums.size()+1, 0);

        for(int i = 1; i< sumBefor.size();i++){
            sumBefor[i] = sumBefor[i-1] + array[i];
        }
        MyPrintOne(sumBefor);
    }
    
    void update(int index, int val) {
        int valIndex = index +1;
        int diff = val - array[valIndex];
        array[valIndex] = val;
        for(int i= valIndex; i< sumBefor.size(); i++){
            sumBefor[i] += diff;
        }

    }
    
    int sumRange(int left, int right) {
        int valLeft = left +1;
        int valRight = right+1;
        cout << "sumRange= " << sumBefor[valRight] - sumBefor[valLeft -1] << endl;
        return sumBefor[valRight] - sumBefor[valLeft -1];

    }
public:
    vector<int>array;
    vector<int>sumBefor; // 记录前缀合
};



int main()
{
    vector<int>nums = {1,3,5};
    NumArray s1(nums);
    s1.sumRange(0,2);
    s1.update(1,2);
    s1.sumRange(0,2);
    

    cout << "hello" << endl;
    return 0;
}