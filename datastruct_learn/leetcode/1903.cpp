#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        string resu = "";
        for(int i =num.length()-1; i >= 0; i--){
            if((num[i]- '0' ) % 2 == 1){
                resu = num.substr(0, i-0 +1);
                break;
    
            }
        }
        return resu;
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}