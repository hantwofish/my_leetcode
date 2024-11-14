#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i < s.length() &&  s[i] == '0'){
            i++;
        }
        while(j >= 0 &&  s[j] == '0'){
            j--;
        }

        int k = i + 1;
        while(k < j){
            if(s[k] == '0'){
                return false;
            }
            k++;
        }
        return true;
    }
};

int main()
{
    string s= "1001";
    Solution s1;
    s1.checkOnesSegment(s);
    cout << "hell22o" << endl;
    return 0;
}