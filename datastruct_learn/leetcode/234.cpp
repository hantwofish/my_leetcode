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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        vector<int>data;
        while(temp!= nullptr){
            n++;
            data.push_back(temp->val);
            temp = temp->next;
        }
        cout << "N= " << n << endl;
        for(int i = 0,j = n-1; i < j; i++,j--){
            // if(getVal(head, i) != getVal(head, j)){
            //     return false;
            // }
            if(data[i] != data[j]) return false;
        }
        return true;
    }
private:
    int getVal(ListNode* head, int index)
    {
        ListNode* temp = head;
        while(index > 0){
            temp =temp->next;
            index--;
        }
        return temp->val;
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