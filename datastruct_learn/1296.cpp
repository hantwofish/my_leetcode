#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        for(auto &i : nums){
            u_map[i]++;
        }
        auto it = u_map.begin();
        while (it != u_map.end())
        {
            cout << "key= " << it->first << " -> " << it->second << endl;
            it++;
        }
        

        sort(nums.begin(), nums.end());
        for(auto &i : nums){
            if(u_map[i] == 0) continue;
            for(int j = i  ; j < k + i; j++){
                if(u_map[j] == 0) {
                    cout << "i= " << i << " j = " << j << endl;
                    return false;
                } 
                u_map[j]--;
            }

        }
        cout << "return true" << endl;
        return true;
    }
private:
    unordered_map<int,int>u_map;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    vector<int>nums = {1,2,3,3,4,4,5,6};
    int k = 4;
    s1.isPossibleDivide(nums, k);
    

    cout << "hell22o" << endl;
    return 0;
}