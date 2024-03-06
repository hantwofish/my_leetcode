#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        for(int i = 0; i< s.length(); i++){
            if(s[i] == '('){
                stk.push("(");

            }else if(s[i] == ')'){
                string top_val = stk.top();
                if(top_val == "("){
                    stk.pop();
                    stk.push("1");
                    int top_1 = stoi(stk.top());
                    stk.pop();

                    if(!stk.empty() && stk.top() != "(" ){// 为数字
                        int top_2 = stoi(stk.top());
                        stk.pop();
                        stk.push( to_string( top_1 + top_2) );
                    }else{
                        stk.push( to_string( top_1 ) );
                    }


                }else{ // 为数字
                    int temp = stoi(top_val) * 2;
                    stk.pop(); // 数字弹出
                    if(!stk.empty() && stk.top() == "(" ){
                        stk.pop(); // 弹出 （
                        stk.push(to_string(temp));
                    }





                    if(!stk.empty() && stk.top() != "(" ){ // 数字
                        int val = stoi(stk.top());
                        stk.pop(); 
                        if(!stk.empty()){
                            if(stk.top() != "("){
                                int val_2 = stoi(stk.top());
                                stk.pop(); 
                                stk.push(to_string(val + val_2));
                            }else{
                                stk.push(to_string(val));
                            }
                            
                        }else {
                            stk.push(to_string(val));
                        }
                        
                        
                    }
                }

            }

        }
        cout << "stk.size= " << stk.size() << " val= " << stk.top() << endl;
        return stoi(stk.top());

    }
private:
    stack<string>stk;
};  

int main()
{
    Solution s1;
    // s1.calMaxArray();
    string str = "(()(()))";
    // string str = "(())";
    //  string str = "()()()";
    s1.scoreOfParentheses(str);
    

    cout << "hell22o" << endl;
    return 0;
}