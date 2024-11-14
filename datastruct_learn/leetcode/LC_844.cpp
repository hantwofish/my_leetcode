#include"../STLCOMMON.h"

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {

        if(removeadd(s) == removeadd(t)){
            return true;
        }
        return false;
        

    }

    string removeadd(string s)
    {
        string str1;
        stack<char> stk;
        for(auto i : s){
            if((i == '#')){
                if( (!stk.empty())){
                    stk.pop();
                }
                
            }else{
                stk.push(i);
            }
        }
        while(!stk.empty()){
            str1 += stk.top();
            stk.pop();
        }
        cout << str1 << endl;

        return str1;
    }
};


int main()
{
    Solution s1;
    string s = "y#fo##f";
    string t = "y#f#o##f";

    bool flag = s1.backspaceCompare(s,t);

    return 0;
}