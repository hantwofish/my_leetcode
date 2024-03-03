#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vaild.resize(s.length(), 0);

        for(int i= 0; i< s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z') {
                // resu += s[i];
                vaild[i] = 1;
                continue;
            }
            if(s[i] == '('){
                stk.push(i);
                // resu += s[i];
                continue;
            }
            if(s[i] == ')'){
                if(stk.empty()){
                    pop_nums++;
                }else{
                    if(s[stk.top()]=='('){
                        vaild[stk.top()] = 1;
                        stk.pop();
                        vaild[i] = 1;
                    }
                }
            }
        }

        for(int i = 0; i < s.length(); i++){
            if(vaild[i] == 1){
                resu += s[i];
            }
        }
        cout << "pop_num= " << pop_nums  << " resu= " << resu << endl;
        return resu;
    }
private:
    stack<int>stk;
    int pop_nums = 0;
    string resu = "";
    vector<int>vaild;
};

int main()
{
    Solution s1;
    // string str = "lee(t(c)o)de)";

    string str = "a)b(c)d";

    // string str = "))((";
    s1.minRemoveToMakeValid(str);
    
    

    cout << "hell22o" << endl;
    return 0;
}