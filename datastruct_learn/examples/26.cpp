#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int>record;    
        int i = 0;
        int del_num = 0;
        for(int i = 0; i < nums.size(); i++){
            record[nums[i]]++;
        }
        del_num = nums.size() - record.size();
        cout << "recod.size= " << record.size() << endl;
        cout << "del_num = " << del_num << endl;

        record.clear();

        while(i < nums.size() - del_num){
            int temp = nums[i];
            record[temp]++;
            // cout << "temp= " << temp << endl;
            if( record[temp] > 1){
                // delete it
                dele_elm(nums, i);
                continue;
            }else{
                i++;
            }
        }
        MyPrintOne(nums);
        cout << "size= "  << record.size() << endl;
        return record.size();
        
    }
    void dele_elm(vector<int>&nums, int index)
    {
        int dele_val = nums[index];
        for(int i = index + 1; i< nums.size(); i++){
            nums[i-1] = nums[i];
        }
        nums[nums.size()-1] = dele_val;

        return;
    }

};

int main()
{
    Solution s1;
   vector<int>nums = {0,0,1,1,1,2,2,3,3,4};
   s1.removeDuplicates(nums);
   cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe