
#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string resu = "";
        for(int i = 0; i< s.length();i++){
            string temp_1 = findMaxStr(s, i, i);

            if(temp_1.length() > resu.length()){
                resu = temp_1;
            }
            string temp_2 = findMaxStr(s, i, i+1);
            if(temp_2.length() > resu.length()){
                resu = temp_2;
            }
        }
        cout << "main resu " << resu << endl;
        return resu;
    }
    string findMaxStr(string s, int left, int right)
    {
        string resu = "";
        
        while(left>= 0 && right < s.length() && s[left] == s[right] ){
            resu = s.substr(left, right-left +1);
            left--;
            right++;
        }
        
        cout << "left= " << left << " right= " << right << " resu= " << resu << endl;
        return resu;
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    // string s = "babad";
    // string s = "cbbd";
    string s = "a";
    s1.longestPalindrome(s);
    
    

    cout << "hell22o" << endl;
    return 0;
}