#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    string finalString(string s) {
        string resu = "";
        for(int i= 0; i< s.length(); i++){
            if(s[i] == 'i'){
                reverse(resu.begin(), resu.end());
            }else{
                resu = resu + s[i];
            }
        }
        cout << "resu=" << resu << endl;
        return resu;
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    string s = "string";
    s1.finalString(s);
    

    cout << "hell22o" << endl;
    return 0;
}