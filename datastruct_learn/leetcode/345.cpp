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
    string reverseVowels(string s) {
        int front = 0;
        int end = s.length()-1;
        while(front <= end){
            while(front < s.length() && isVaild(s[front]) != true) {
                front++;
                if(front >= s.length() || front >= end) return s;;

            }
            

            while(end >=0 && isVaild(s[end]) != true){
                end--;
                if(end < 0 || end < front) return s;;

            } 
            cout << "front= " << s[front] << " end= " << s[end] << endl;
            swap(s[front], s[end]);
            cout << "temp= " << s <<endl;
            front++;
            end--;
        }
        cout << "s= " << s <<endl;
        return s;
    }
private:
    bool isVaild(char c)
    {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
            
            default:
                break;
        }
        return false;
    }
};

int mainFunc()
{
    Solution s1;
    string str = "aA";
    string resu = s1.reverseVowels(str);
    cout << "resu= " << resu <<endl;

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