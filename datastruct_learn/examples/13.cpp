#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int val_output = 0;
        int start_Index = 0;
        int N = s.length();

        char front_char = '0';
        char behin_char = '0';
        int front_val = char_to_val(front_char);
        int behin_val = char_to_val(behin_char);
        int tem_val = 0;
        int i = 0;

        while(i < N  ){
            if(i == N -1){
                tem_val = (char_to_val(s[i]));
                cout << " tem_val= " << tem_val << endl;
                val_output +=  tem_val;
                break;
            }
            front_char = s[i];
            behin_char = s[i+1];
            front_val = char_to_val(front_char);
            behin_val = char_to_val(behin_char);
            tem_val = 0;

            if(  front_val == 1 && (behin_val == 5 || behin_val == 10)  ){
                tem_val= (behin_val - front_val);
                i=i+2;
            }else if(front_val == 10 && (behin_val == 50 || behin_val == 100) ){
                tem_val= (behin_val - front_val);
                i=i+2;
            }else if(front_val == 100 && (behin_val == 500 || behin_val == 1000) ){
                tem_val= (behin_val - front_val);
                i=i+2;
            }else{
                tem_val=  front_val;
                i++;
            }
            val_output +=  tem_val;

            cout << "front_char=  "<< front_char << " behin_char= " << behin_char << endl;
            cout << "front_val=  " << front_val  << " behin_val= " << behin_val << " " << tem_val << endl;

        }

  


        cout << "return " << val_output << endl;
        return val_output;
        
    }
private:
    int char_to_val(char chr)
    {
        int val = 0;
        switch (chr)
        {
        case 'I':
            val = 1;
            break;
        case 'V':
            val = 5;
            break;
        case 'X':
            val = 10;
            break;
        case 'L':
            val = 50;
            break;
        case 'C':
            val = 100;
            break;
        case 'D':
            val = 500;
            break;
        case 'M':
            val = 1000;
            break;
        
        default:
            break;
        }
        return val;
    }
};

int main()
{
    Solution s1;
    string s = "MCDLXXVI";
    s1.romanToInt(s);

    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 拷贝文件：./file_run.sh 00_00.cpp
// 运行文件  ./file_copy.sh  00_00.cpp