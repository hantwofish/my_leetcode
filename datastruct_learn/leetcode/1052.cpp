#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int out_val = 0;
        for(int i= 0; i< customers.size(); i++){
            int resu = getVal(customers, i, minutes);
            for(int j = 0; j < customers.size(); j++ ){
                if( j >= i && j <= minutes + i - 1){
                    continue;
                }
                if(grumpy[j] == 1){
                    resu += customers[j];
                }
            }
            cout << "resu = " << resu << endl;
            out_val= max(out_val, resu);
        }
        return out_val;


    }
    int getVal(vector<int>& customers, int start, int minutes)
    {
        int resu = 0;
        for(int i = start; i <= minutes + start - 1; i++){
            if(i >= customers.size()){
                break;
            }
            resu += customers[i];
        }
        return resu;
    }
}; 

int main()
{
    Solution s1;
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int minutes = 3;
    s1.maxSatisfied(customers, grumpy, minutes);
    cout << "hell22o" << endl;
    return 0;
}