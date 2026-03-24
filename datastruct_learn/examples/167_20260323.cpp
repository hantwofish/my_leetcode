#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
// #include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start_index = 0;
        int end_index = numbers.size()-1;
        while(start_index < numbers.size() && end_index >=0  &&   numbers[start_index] + numbers[end_index] != target){
            if(numbers[start_index] + numbers[end_index] > target){
                end_index--;
            }else if(numbers[start_index] + numbers[end_index] < target){
                start_index++;
            }else if(numbers[start_index] + numbers[end_index] == target){
                return {start_index, end_index};
            }
        }

        return {start_index, end_index};
        
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