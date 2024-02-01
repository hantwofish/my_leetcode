#include"../STLCOMMON.h"

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        cout << "str= " << s << endl;
        int N = s.size();
        vector<int>match(N,0);

        stack<int>stk;
        for(int i = 0 ; i< N; i++){
            char tmp = s[i];
            if(tmp == '('){
                stk.push(i);
            }else if(tmp == ')'){
                if( !stk.empty() && s[stk.top()]=='('){
                    match[stk.top()] = i;
                    match[i] = stk.top();
                    stk.pop();
                }else{
                    stk.push(i);
                }


            }
        }
        MyPrintOne(match);
        // 找出最大的区间
        int ans = 0;
        int tempAns = 0;
        int index = 0;
        while(index < match.size()){
            // cout << "index= " << index << endl;
            if(match[index] != 0){
                tempAns += (match[index] - index + 1);
                index = match[index] + 1;
                // cout << "tempAns= " << tempAns << endl;
            }else{
                tempAns = 0;
                index = index + 1;
            }
            ans = max(ans, tempAns);
            
        }



        return ans;
    }

public:
    
};

int main()
{
    Solution s1;
    string str = "())(())()()()())";
    int resu =  s1.longestValidParentheses(str);
    cout << "resu= " << resu << endl;
    return 0;
}