#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        
        int tiems= 0;
        while(mainTank > 0 ){
            mainTank--;
            tiems++;
            if(tiems % 5 == 0 && additionalTank > 0){
                mainTank++;
                additionalTank--;
            }
        }
        cout << "tiems= " << tiems << endl;
        return tiems * 10;
    }
};
 

int main()
{
    int mainTank = 9;
    int additionalTank = 1;
    Solution s1;
    s1.distanceTraveled(mainTank, additionalTank);
    cout << "hell22o" << endl;
    return 0;
}