#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        // vector<int> indexArray;
        int resu = 0;
        for(int i = 0; i < nums.size(); i++){
            if(claTimes(inttobitstring(i), k)){
                resu += nums[i];
            }
        }
        return resu;
    }
private:
    string inttobitstring(int k)
    {
        string resu = "";
        while(k > 0){
            resu += to_string(k % 2);
            k = k /2;
        }
        reverse(resu.begin(), resu.end());
        // cout << resu << endl;
        return resu;
    }

    bool claTimes(string str, int k)
    {
        int times = 0;
        for(int i = 0; i< str.length(); i++){
            if(str[i] == '1'){
                times++;
            }
        }
        return (times == k);

    }
};



int main()
{
    Solution s1;
    int n  =10;


    

    cout << "hell22o" << endl;
    return 0;
}