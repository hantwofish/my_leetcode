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
    int maximumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end());
        reverse(cards.begin(), cards.end());
        for(auto i:cards){
            cout << " " <<i ;
        }
        cout <<endl;

        int sum = 0;
        int chose_min_1 = INT32_MAX;
        int chose_min_0 = INT32_MAX;
        for(int i = 0; i< cnt; i++){
            sum = sum + cards[i];
            if(cards[i] % 2 == 0 && cards[i] < chose_min_0){
                chose_min_0 = cards[i];
            }
            if(cards[i] % 2 == 1 && cards[i] < chose_min_1){
                chose_min_1 = cards[i];
            }

        }
        
        if(sum %2 == 0) return sum;

        int beind_max_1 = 0;
        int beind_max_0 = 0;
        for(int i = cnt; i < cards.size(); i++){
            if(cards[i] % 2 == 1){
                beind_max_1 = cards[i];
                break;
            }
        }
        for(int i = cnt; i < cards.size(); i++){
            if(cards[i] % 2 == 0){
                beind_max_0 = cards[i];
                break;
            }
        }
cout <<"sum = " <<sum <<" chose_min_0=  "<<chose_min_0 <<" chose_min_1= " <<chose_min_1 <<endl;
cout << "beind_max_0= " << beind_max_0 << " beind_max_1= " << beind_max_1 << endl;
        // 1. 换掉选择中最小的偶数
        int temp1 = sum;
        if(chose_min_0 != INT32_MAX && beind_max_1 != 0){
            temp1 -= chose_min_0;
            temp1 += beind_max_1;
        }
        cout << "chose temp1 = " << temp1 << endl;
        // 2. 换掉选择中最小的奇数
        int temp2 = sum;
        if(chose_min_1 != INT32_MAX && beind_max_0 != 0){
            temp2 -= chose_min_1;
            temp2 += beind_max_0;
            cout << "chose tem = " << temp2 << endl;


        }

        if(temp1 % 2== 1) {
            temp1 = 0;
        }
        if(temp2 % 2 == 1){
            temp2 = 0;
        }
        
        
        return max(temp1, temp2);
    }
};

int mainFunc()
{
    Solution s1;
    vector<int>nums = {7,4,1};
    s1.maximumScore(nums, 1);

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