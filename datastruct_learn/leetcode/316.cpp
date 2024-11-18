#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        for(int i=0; i<s.length();i++){
            unmap[s[i]]++;
            visited[s[i]] = false;
        }
        stack<char>stk;
        for(int i= 0; i< s.length();i++){
            char tem = s[i];
            unmap[tem]--;
            if(visited[tem]) continue;
            // 单调栈，弹出大于 tem 的元素
            while(!stk.empty() && tem < stk.top()){
                char top_val = stk.top();
                // 如果后面还有 top_val 则弹出，否则后面则没有此元素了
                if(unmap[top_val] > 0 ){
                     stk.pop();
                    visited[top_val] = false;
                }else{
                    break;
                }
               
            }
            stk.push(tem);
            visited[tem] = true;
        }

        string resu = "";
        while(!stk.empty()){
            resu = stk.top() + resu;
            stk.pop();
        }

        return resu;
    }
private:
    unordered_map<char, int>unmap;
    unordered_map<char, bool>visited;
};

int main()
{
    Solution s1;
    string s = "bcac";
    string str =  s1.removeDuplicateLetters(s);

    

    cout << "str=" << str  << endl;
    return 0;
}