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
                    stk.pop(); // 弹出 "("
                    stk.push("1");

                    if(stk.size() <= 1) continue;

                    // vector<string>vec_str;
                    // 判断放入后，是否两个数字相邻
                    stack<string>stk_2 = stk;
                    stk_2.pop();
                    if(stk_2.top() != "(" ){
                        int top_2 = stoi(stk.top());
                        stk.pop();
                        int top_1 = stoi(stk.top());
                        stk.pop();

                        stk.push( to_string( top_1 + top_2) );
                    }
                    


                    

                    // int top_1 = stoi(stk.top());
                    // stk.pop();

                    // if(!stk.empty() && stk.top() != "(" ){// 为数字
                    //     int top_2 = stoi(stk.top());
                    //     stk.pop();
                    //     stk.push( to_string( top_1 + top_2) );
                    // }else{
                    //     stk.push( to_string( top_1 ) );
                    // }


                }else{ // 为数字
                    int temp = stoi(top_val);
                    stk.pop();
                    
                    if(!stk.empty() && stk.top() == "(" ){
                        stk.pop(); // 弹出 （
                        stk.push(to_string(temp *2));
                    }

                    // 判断放入后，是否两个数字相邻

                    stack<string>stk_2 = stk;
                    stk_2.pop(); // 弹出刚放入的数字
                    if(!stk_2.empty() && stk_2.top() != "(" ){ // 数字
                        int stk_2_top_val = stoi(stk.top());
                        stk.pop();

                        int stk_1_top_val = stoi(stk.top());
                        stk.pop();
                        stk.push(to_string(stk_1_top_val + stk_2_top_val));

                    }




                //     if(!stk.empty() && stk.top() != "(" ){ // 数字
                //         int val = stoi(stk.top());
                //         stk.pop(); 
                //         if(!stk.empty()){
                //             if(stk.top() != "("){
                //                 int val_2 = stoi(stk.top());
                //                 stk.pop(); 
                //                 stk.push(to_string(val + val_2));
                //             }else{
                //                 stk.push(to_string(val));
                //             }
                            
                //         }else {
                //             stk.push(to_string(val));
                //         }
                        
                        
                //     }
                }

            }

        }
        cout << "stk.size= " << stk.size() << " val= " << stk.top() << endl;
        return stoi(stk.top());

    }
private:
    stack<string>stk;
    // vector<string>vec_str;
};  

int main()
{
    Solution s1;
    // s1.calMaxArray();
    // string str = "(()(()))";
    // string str = "(())";
     string str = "()()()";
    s1.scoreOfParentheses(str);
    

    cout << "hell22o" << endl;
    return 0;
}