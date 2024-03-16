#include"STLCOMMON.h"

using namespace std;


class Solution {
public:
    bool isSubsequence(string subStrings, string totalStr) {
        int StartFindIndex = 0;
        for(int i = 0; i < subStrings.size(); i++){
            if(totalStr.find(subStrings[i], StartFindIndex) == string::npos){
                return false;
            }else{
                int index = totalStr.find(subStrings[i], StartFindIndex);
                StartFindIndex = index + 1;

            }
        }
        return true;
    }
};

int main()
{
    Solution s1;
    vector<int>aaa;
    string totoal = "ahbgdaghc";
    string halfString = "acb";
    cout << " xx " << s1.isSubsequence(totoal,halfString) << endl;
    cout << " end " << endl;
    return 0;
}