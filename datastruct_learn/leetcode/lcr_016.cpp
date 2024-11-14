#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lent = 0;
        for(int i = 0; i< s.length(); i++){
            for(int len = 1; len <= s.length() -i ; len++){
                string subStr = s.substr(i, len);
                // cout << subStr << endl;
                if(isSinglChar(subStr)){
                    int temp = subStr.length();
                    lent= max(lent, temp);
                }else{
                    break;
                }
            }
        }
        return lent;
    }
    bool isSinglChar(string str)
    {
        if(notSingel.find(str) != notSingel.end()){
            return false;
        }
        set<char>mySet;
        for(int i = 0; i< str.size(); i++){
            if(mySet.find(str[i]) == mySet.end()){
                mySet.insert(str[i]);
            }else{
                notSingel.insert(str);
                return false;
            }
        }
        return true;
    }
private:
    set<string>notSingel;
};
 

int main()
{
    Solution s1;
    string s = "abcabcbb";
    int len =  s1.lengthOfLongestSubstring(s);
    cout << "len= " << len << endl;
    cout << "end" << endl;
    return 0;
}