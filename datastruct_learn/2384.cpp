#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        int val =1;
        long long resu = 0;
        int cur_size = 0;

        if( n == target ){

            return sumHalf(n);
        }
        while(cur_size < n){
            if( isPutValid(val, target) ){
                // nums.push_back(val);
                cur_size++;
                // storeSet.insert(val);
                storeMap[val] = 1;

                cout << "put val = " << val << endl;
                resu += val;
                if(resu > MOD){
                    resu -= MOD;
                }
            }
            val++;
        }
        // cout << "resu= " << resu << endl;
        return resu;

    }
    bool isPutValid(int val, int target)
    {
        if(val >= target) {
            return true;
        }

        if( storeMap[target-val] == 0 ){
            return true;
        } else{
            return false;
        }
        // auto it = storeSet.begin();
        // while(it != storeSet.end()){
        //     if(*it + val == target){
        //         return false;
        //     }
        //     it++;
        // }
        // return true;

    }

    int sumHalf(int N)
    {
        // int leftSize = N /2;
        // int leftSum = ( 1 +  (1 + leftSize -1) ) *  (leftSize) / 2;

        // int rightSize = N - leftSize;
        // int rightSum = (N + (N + rightSize  -1)) * (rightSize) / 2;

        // return leftSum + rightSum;
        long long tem = N;
        long long resu = (3*tem*tem)/ 4;
        if(resu > MOD){
            return resu % MOD;
        }
        return resu;
    }

private:
    // vector<int>nums;
    const int MOD =1e9 + 7;
    unordered_set<int>storeSet;
    unordered_map<int, int>storeMap;
};

int main()
{
    Solution s1;
    int n = 11;
    int target = 1;
    int resu = s1.minimumPossibleSum(n, target);
    cout << "main resu= " << resu << endl;
    

    cout << "hell22o" << endl;
    return 0;
}