#include"../STLCOMMON.h"

using namespace std;
class Solution {
public:
    bool isValid(string str) {
        if(str.size() == 0){
            return true;
        }

        stack<char> stk;
        stk.push(str[0]);
        char tmpTop;

        for(int i = 1; i < str.size(); i++){
            cout << "i= " << i << " " << str[i] << endl;
            char tmp = str[i];
            if(!stk.empty()){
                tmpTop = stk.top();
            }
            if(tmp == '(' || tmp == '{' || tmp == '['){
                stk.push(tmp);
            }else if(tmp == ')'){
                if(stk.empty()){
                    return false;
                }
                if( tmpTop == '(' ){
                    stk.pop();
                }else{
                    return false;
                }

            }else if(tmp == '}'){
                if(stk.empty()){
                    return false;
                }
                if( tmpTop == '{' ){
                    stk.pop();
                }else{
                    return false;
                }

            }else if(tmp == ']'){
                if(stk.empty()){
                    return false;
                }
                if( tmpTop == '[' ){
                    stk.pop();
                }else{
                    return false;
                }
            }
        }
        cout << " size= " << stk.size() << endl;
        if(stk.empty()){
            return true;
        }

        return false;
    }
public:
    bool resu;
};

int main()
{
    Solution s1;
    string str = "(])";
    cout << "str.size()= " << str.size() << endl;
    bool resu = s1.isValid(str);
    cout << "resu= " << resu << endl;
    return 0;

}