#include"../STLCOMMON.h"
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        for(int i = 0; i < nums.size(); i++){
            m_map[nums[i]].push_back(i);
        }
        auto it = m_map.begin();
        while(it != m_map.end()){
            if((it->second).size ()== 1){
                it++;
                continue;
            }
            vector<int> tmp = it->second;
            sort(tmp.begin(), tmp.end());
            for(int i = 1; i< tmp.size(); i++){
                if(tmp[i] - tmp[i-1] <= k){
                    return true;
                }
            }

            it++;
        }
        return false;
    }

public:
    unordered_map<int, vector<int>>m_map;
};



int main()
{
    vector<int> nums = {1,0,1,1};
    int  k = 1;
    Solution s1;
    cout << s1.containsNearbyDuplicate(nums,k) << endl;
    return 0;
}