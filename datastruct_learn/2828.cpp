#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string str = "";
        for(int i = 0; i< words.size();i++){
            if(words[i].size()==0) continue;
            str = str + words[i][0];
        }
        return (str == s);
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}