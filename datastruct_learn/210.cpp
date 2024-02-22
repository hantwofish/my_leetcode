#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int resu = left;
        for(int i = left + 1; i<= right ;i++){
            resu = resu & i;
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