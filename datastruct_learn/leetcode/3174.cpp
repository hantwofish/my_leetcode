#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;




class Solution {
public:
    string clearDigits(string s) {
        while(  1 ){
            int index = getNumIndex(s)  ;
            cout << "index = " << index << endl;
            if(index != -1){
                if(index >=  0){
                    s.erase(index, 1);
                }
                if(index -1 >= 0){
                    s.erase(index -1, 1);
                }
                
                
                cout << "s= " << s << endl;

            }else{
                break;
            }
        }
        return s;
        
    }
    int getNumIndex(string str)
    {
        int ret = -1;
        // cout << "str = " << str << endl;
        for(int i = 0; i< str.size(); i++){
            int num = str[i] - '0';
            // cout << "num = " << num << endl;
            if(num >= 0 && num <= 9){
                return i;
            }
        }
        return ret;
    }
};

int mainFunc()
{
    Solution s1;
    string str = "6cb34";
    string res = s1.clearDigits(str);
    cout << "res= " << res << endl;

    return 0;
}

int main()
{

    if(mainFunc() == 0){
        // timer_thread.join(); // 等待计时器线程完成
        cout << "[info] main end" << endl << endl;
        return 0;
    }

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe