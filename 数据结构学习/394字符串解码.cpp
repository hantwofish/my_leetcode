#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char>stk;
        for(int i = 0; i< s.length();i++){
            if(stk.empty()){
                stk.push(s[i]);
                continue;
            }
            char temp = s[i];
            if( temp != ']'){
                stk.push(temp);
                continue;
            }
            // temp == ']'
            string strvalue = "";
            while(!stk.empty() && stk.top() != '['){
                strvalue = stk.top() + strvalue;
                stk.pop();
            }
            cout << "strvalue= " << strvalue << endl;
            if(!stk.empty() && stk.top() == '[') stk.pop();
            string intvalue = "";
            while(!stk.empty() && stk.top() <= '9' && stk.top() >= '0' ){
                intvalue = stk.top() + intvalue;
                stk.pop();
            }
            cout << "intvalue= " << intvalue << endl;
            string calvalue = "";
            int times = stoi(intvalue);
            for(int j = 0; j < times; j++){
                calvalue += strvalue;
            }
            cout << "calvalue= " << calvalue << endl;
            for(int k= 0; k < calvalue.size(); k++){
                stk.push(calvalue[k]);
            }

        }

        string resu = "";
        while(!stk.empty()){
            resu += stk.top();
            stk.pop();
        }
        reverse(resu.begin(),resu.end());
        cout << "resu= " << resu << endl;
        return resu;
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    string temp = "10[abc]";
    s1.decodeString(temp);

    

    cout << "hell22o" << endl;
    return 0;
}

// 输入：s = "3[a]2[bc]"
// 输出："aaabcbc"
// 示例 2：

// 输入：s = "3[a2[c]]"
// 输出："accaccacc" accaccacc
// 示例 3：

// 输入：s = "2[abc]3[cd]ef"
// 输出："abcabccdcdcdef" abcabccdcdcdef
