#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
// #include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<vector<int>>stak_nums;
        for(int i = 0; i < intervals.size(); i++){
            vector<int>cur_nums = intervals[i];
            if(stak_nums.empty()){
                stak_nums.push(cur_nums);
                continue;
            }
            vector<int>top_val = stak_nums.top();
            stak_nums.pop();
            int left_1 = top_val[0];
            int left_2 = top_val[1];
            int right_1 = intervals[i][0];
            int right_2 = intervals[i][1];
            if(right_1 <= left_1 && right_2 <= left_1){
                // left_1 = min(left_1, right_1);
                // left_2 =  max(left_2, right_2);
                stak_nums.push({left_1, left_2});
                stak_nums.push({right_1, right_2});
            }else if((right_1 >= left_1 && right_1 <= left_2)   || ( right_2 >= left_1 && right_2 <= left_2  )){
                left_1 = min(left_1, right_1);
                left_2 =  max(left_2, right_2);
                stak_nums.push({left_1, left_2});
            }else if(right_1 > left_2 && right_2 >= left_2){
                stak_nums.push({left_1,left_2});
                stak_nums.push({right_1, right_2});
            }

        }

        vector<vector<int>>output;
        while(!stak_nums.empty()){
            output.push_back(stak_nums.top());
            stak_nums.pop();
        }
        return output;
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