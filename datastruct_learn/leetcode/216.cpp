#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        class BackY backT;
        vector<vector<int>>temp = backT.combine(9,k);
        
        set<vector<int>>resu;
        for(int i = 0; i< temp.size(); i++){
            int resu_te = 0;
            for(int j = 0; j < temp[i].size(); j++){
                resu_te += temp[i][j];
            }
            if(resu_te == n){
                resu.insert(temp[i]);
            }
        }

        vector<vector<int>>out_resu(resu.begin(),resu.end());

        
        cout << "out_resu.size()= " << out_resu.size() << endl;
        return out_resu;
    }
};
 

int main()
{
    Solution s1;
    int k = 2;
    int n = 18;
    vector<vector<int>>resu = s1.combinationSum3(k,n);
    MyPrintTwo(resu);
    cout << "hell22o" << endl;
    return 0;
}