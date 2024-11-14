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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int num = 0;
        while(temp != nullptr){
            num++;
            temp = temp ->next;
        }
        num = num /2;
        temp = head;
        while(num){
            temp = temp ->next;
            num--;
        }
        return temp;
    }   
};

int mainFunc()
{
    Solution s1;

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