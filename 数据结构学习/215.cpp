#include"../STLCOMMON.h"
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,less<int>> preQue;
        for(auto it : nums){
            preQue.push(it);
        }

        int resu =preQue.top();
        for(int i = k; i> 0; i--){
            if(!preQue.empty()){
                resu = preQue.top();
                preQue.pop();
            }

        }

        return resu;
    }
};

int main()
{
    Solution s1;
    int k = 7;
    vector<int>nums= {3,2,1,5,6,4};

    int resu =  s1.findKthLargest(nums,k);
    cout << "resu= " << resu << endl;
    return 0;
}