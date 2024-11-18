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
    vector<string> validStrings(int n) {
        vector<string> resu;
        if(n ==1){
            resu.push_back("0");
            resu.push_back("1");
            return resu;
        }
        int N = n;
        for(int i = 0; i < pow(2, n); i++){
            cout << intTo2str(n, i) << endl;
            string temp = intTo2str(n, i);
            if(strIsVaild(temp)){
                resu.push_back(temp);
                cout << "one resu= " << temp << endl;
            }
        }
        while(1){
            cout << "   xxx " << endl;
        }
        
        return resu;
    }
public:
    // 二进制 转字符
    string intTo2str(const int N, int nums){
        string resu = "";
        while(nums){
            int yu = nums %2;
            nums = nums / 2;
            // cout << yu << " ";
            resu = to_string(yu) + resu;
        }
        // cout << "resu= " << resu << endl;
        int lenSize = resu.size();
        for(int i = 0; i < N - lenSize; i++){
            resu = "0" + resu;
        }
        // cout << "num= " << nums << "  resu= " << resu << endl;
        return resu;
    }
    bool strIsVaild(string str)
    {
        for(int i = 0; i< str.size()-1; i++){
            if(str[i] == '0' && str[i+1] == '0'){
                return false;
            }
        }
        return true;
    }
};

int mainFunc()
{
    Solution s1;
    // s1.intTo2str(4, 2);
    s1.validStrings(3);

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