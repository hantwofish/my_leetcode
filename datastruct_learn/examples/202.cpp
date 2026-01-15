#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>my_Map;
        my_Map.insert(n);

        int val = n;
        while(val != 1){
            string str = to_string(val);
            n = 0;
            for(int i = 0; i< str.length() ; i++){
                int temp = str[i] - '0';
                n += ( temp * temp);
            }

            if(my_Map.find(n) == my_Map.end()){
                my_Map.insert(n);
            }else{
                return false;
            }

            cout << "n= " << n << endl;
            if(n == 1) return true;
            val = n;
        }
        return true;
    }
};

int main()
{

    Solution s1;
    s1.isHappy(19);
    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp