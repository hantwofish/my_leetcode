#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '6'){
                str[i] = '9';
                break;
            }
        }
        return stoi(str);
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