#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>record;
        int N = nums.size();
        for(int i = 0; i< nums.size(); i++){
            record[nums[i]]++;
        }

        int dele_num = 0;
        auto it = record.begin();
        while(it != record.end()){
            if(it->second > 2){
                dele_num += (it->second -2);
            }
            it++;
        }
        cout << "dele_num=  " << dele_num << endl;
        int i = 0;
        while(i < N - dele_num){
            int temp = nums[i];
            if(record[temp] > 2 ){ // delete it
                record[temp]--;
                delete_it(nums, i);
                continue;
            }else{
                i++;
            }
            
        }

        MyPrintOne(nums);
        cout << " " << N -dele_num  << endl;
        return N - dele_num;

    }
    void delete_it(vector<int>&nums, int dele_index)
    {
        int dele_val = nums[dele_index];
        for(int i = dele_index + 1; i < nums.size(); i++){
            nums[i-1] = nums[i];
        }
        nums[nums.size()-1] = dele_val;
        return;
    }
  
};


int main()
{

    Solution s1;
    // vector<int> nums = {0,0,1,1,1,1,2,3,3};
    vector<int> nums = {1,1,1,2,2,3};
    
    s1.removeDuplicates(nums);
   cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp