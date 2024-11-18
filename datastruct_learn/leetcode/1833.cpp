#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int resu = 0;
        int indes = 0;
        while(coins > 0 && indes < costs.size()){
            if( coins >=  costs[indes]){
                resu++;
                coins = coins - costs[indes];
                indes++;
            }else {
                break;
            }
            
        }
        return resu;
    }
};

int main()
{
    
    cout << "hell22o" << endl;
    return 0;
}