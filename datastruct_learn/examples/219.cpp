#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>my_map;

        for(int i = 0; i< nums.size(); i++){
            my_map[nums[i]].push_back(i);
        }
        auto it = my_map.begin();
        while(it != my_map.end()){
            vector<int>temp = it->second;
            sort(temp.begin(),temp.end());
            for(int i = 1; i < temp.size(); i++){
                if(abs(temp[i] - temp[i-1]) <=k){
                    return true;
                }
            }


            it++;
        }
        return false;
    }
};

int main()
{

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp