#include"../STLCOMMON.h"
#include"../COMMONALO.h"



using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        bitset<32>bitVal(left);
        for(int i =0; i< 32;i++){
            if(bitVal[i] == 0) continue;
            for(long long j = left; j <= right ; j++){
                bitset<32>temp(j);
                if(temp[i] == 0){
                    bitVal[i] = 0;
                    break;
                }else{
                    bitVal[i] = 1;
                }
            }
            // cout<< "i= " << i << " val= " << bitVal[i] << endl;
        }
        return bitVal.to_ulong();

    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    cout << INT32_MAX << endl;
    int left =  1073741824;
    int right =   2147483647;
    int resu = s1.rangeBitwiseAnd(left,right);
    cout << "resu= " << resu << endl;

    

    cout << "hell22o" << endl;
    return 0;
}