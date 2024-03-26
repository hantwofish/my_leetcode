#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int calculate(string s) {
        for(int i=0; i< s.length(); i++){
            char tmp =s[i];
            if(tmp == '(' || tmp == '+' || tmp == '-'){
                stk.push(tmp);
            }else if(tmp >= '0' && tmp <= '9'){

            }else if(tmp == ')'){

                

            }


        }
    }
private:
    stack<char>stk;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}