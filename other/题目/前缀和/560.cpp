#include"../STLCOMMON.h"

using namespace std;



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int>frontSum(N+1,0);
        for(int  i= 0; i < N; i++){
            frontSum[i+1] = frontSum[i] + nums[i];
        }
        MyPrintOne(frontSum);


        int frontIndex = 0;
        int SeconIndex = 0;
        int resuCount = 0;
        // 前缀和， 次数
        unordered_map<int, int>mapStor;
        for(int i = 0; i < frontSum.size(); i++){

            int temp = frontSum[i] -k ;
            cout << "temp " << temp << endl;
            auto it  = mapStor.find(temp);
            // if(it == mapStor.end()){
            //     mapStor[frontSum[i]]++;
            // }else{
            //     mapStor[frontSum[i]]++;
            //     resuCount ++;
                
            // }
            if(it != mapStor.end()){
                resuCount += it->second;
            }
            mapStor[frontSum[i]]++;
        }


        cout << "resuCount= " << resuCount << endl;
        return resuCount;
    }
};
int main()
{
    vector<int>nums = {1,-1,0};
    MyPrintOne(nums);
    int k =0;
    Solution s1;
    int resu = s1.subarraySum(nums,k);
    //cout << "resu= " << resu << endl;
    cout << "end...." << endl;
    return 0;
}