#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>record;
        for(auto i : nums){
            record[i]++;
        }
        int N = nums.size() /2;
        auto it = record.begin();
        while(it != record.end()){
            if(it->second > N){
                return it->first;
            }
            it++;
        }
        return 0;
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