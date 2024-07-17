#include"../STLCOMMON.h"
#include"../COMMONALO.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../TREE.h"

#define TIMEINTERVAL 1

using namespace std;


class Solution2 {
public:
    int countBinarySubstrings(string s) {
        record.resize(2,0);
        int resu = 0;
        for(int i = 0; i< s.length();i++){
            record[0] = 0;
            record[1] = 0;
            record[s[i] - '0']++;
            for(int j = i+1; j < s.length(); j++){
                record[s[j] - '0']++;

                if(record[0] == record[1] ){
                    string temp = s.substr(i, j -i +1);
                    string leftVal(temp.size()/2 ,'0');
                    string rightVal(temp.size()/2 ,'1');
                    if(temp == leftVal + rightVal || temp == rightVal + leftVal){
                        resu++;
                        cout << "sub ="  << temp << endl;
                    }
                }
            }
        }
        return resu;
    }
private:
    vector<int>record;
};

class Solution {
public:
    int countBinarySubstrings(string s) {
        int end = 0;
        int front = end;
        vector<int>num ;
        while(front < s.length()){

            while(front < s.length() &&  s[front] == s[end]){
                front++;
            }
            cout << s.substr(end, front -1 -end +1) <<  " " << front -end << endl;
            num.push_back(front - end); 
            end = front;  
            
        }

        int resu = 0;
        for(int i = 1; i < num.size(); i++){
            cout <<"num= " <<num[i] << endl;
            resu = resu + min(num[i], num[i-1]);
        }
        return resu;

    }
};

int mainFunc()
{
    Solution s1;
    string str = "00111011";
    s1.countBinarySubstrings(str);
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