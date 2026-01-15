#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, vector<int>> data_map;
        for(int i = 0; i< nums.size(); i++){
            data_map[nums[i] ].push_back(i);
        }  
        set<vector<int>>my_Set;      
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                int diff_num = 0 - nums[i] - nums[j];
                vector<int>temp = data_map[diff_num];
                for(int k = 0; k < temp.size(); k++){
                    if(temp[k] != i && temp[k] != j){
                        cout << i << " " << j << " " << temp[k] << endl;
                        // cout << nums[i] << " " << nums[j] << " " << diff_num << endl;
                        // cout << nums[i] << " " << nums[j] << " " << nums[temp[k] ] << endl;
                        vector<int>temp2;
                        temp2.push_back(nums[i]);
                        temp2.push_back(nums[j]);
                        temp2.push_back(nums[temp[k]]);
                        sort(temp2.begin(), temp2.end());

                        my_Set.insert(temp2);
                    }
                    
                }
            }
        }

        vector<vector<int>>result;
        auto it = my_Set.begin();
        while(it != my_Set.end()){
            result.push_back(*it);
            it++;
        }
        return result;

    }
};


int main()
{
    Solution s1;
    vector<int>nums = {-1,0,1,2,-1,-4};
    s1.threeSum(nums);
    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp