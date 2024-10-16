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
    int findMinDifference(vector<string>& nums) {
        int resu = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size(); i++){
            cout << "i= " << nums[i] << endl;
        }
        for(int i = 0; i< nums.size(); i++){
            for(int j = i +1; j <nums.size(); j++ ) {
                int temp = diff_num(nums[i], nums[j]);
                if(temp == 0) return 0;
                resu = min (resu, temp);
            }
            
        }
        return resu;
    }
    int diff_num(string str1, string str2)
    {
        if(str1 == str2) return 0;
   
        string  st3 = str1.substr(0,2);
        int hour1 = stoi(st3);
        st3 = str1.substr(3,2);
        int min1 = stoi(st3);
        st3 = str2.substr(0,2);
        int hour2 = stoi(st3);
        st3 = str2.substr(3,2);
        int min2 = stoi(st3);
        // cout << hour1 << " : " <<min1 << " , " <<hour2 << " : " <<min2 << endl;
        int num1= hour1 *60 + min1;
        int num2 = hour2 *60 + min2;
        int num3 = (hour2 + 24 ) *60 + min2;

        int diff1 = abs(num1 - num2);
        int diff2 = 24 * 60 - num2 + num1;

        // cout << num1 << " " << num2 << " " << num3 << " | " << diff1 << " " << diff2 <<endl;
        return  min(diff1, diff2);
    }
};

int mainFunc()
{
    Solution s1;
    vector<string> nums = {"23:59","00:00"};
    int resu=  s1.findMinDifference(nums);
    cout << "resu= " << resu << endl;
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