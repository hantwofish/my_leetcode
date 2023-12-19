#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string str) {
        string s = str;
        int left  = 0;
        int right = s.size()-1;
        while(left < right ){
            if(s[left] == s[right]){
                continue;
            }else {
                char temp = min(s[left],s[right]);
                s[left] = temp;
                s[right] = temp;
            }
            left++;
            right--;
            
        }
        
        return s;
    }
};




int main()
{
    Solution s1;
    string str = "aa";
    string resu = s1.makeSmallestPalindrome(str);
    cout << "resu= " << resu << endl;
    
    return 0;
}