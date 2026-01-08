#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int equal_Num = 0;
        for(auto i : nums){
            if(i == val){
                equal_Num++;
            }
        }     
        if(equal_Num == 0 || equal_Num == nums.size()){
            return  nums.size()- equal_Num;
        }

        int temp_index = 0;
        int i = 0;
        while (i < nums.size() - equal_Num ){
            cout << " temp_index= " << i << endl;
            if(nums[i] == val){
                dele_ele(nums, i);
                i = 0;
                continue;
            }
            i++;
        }
        // MyPrintOne(nums);
         return  nums.size()- equal_Num;

    }
    void dele_ele(vector<int>&nums , int dele_index)
    {
        int temp_val = nums[dele_index];
        cout << "dele_del " << dele_index << endl;
        for(int i = dele_index + 1; i < nums.size(); i++){
            nums[i-1] = nums[i];
        }
        nums[nums.size()-1] = temp_val;
        MyPrintOne(nums);
    }
};

int main()
{
    // vector<int>nums = {3,2,2,3}; 
    vector<int>nums ={0,1,2,2,3,0,4,2};
    MyPrintOne(nums);
    // int val = 3;
    int val = 2;
    Solution s1;
    s1.removeElement(nums, val);

   cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe