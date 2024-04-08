#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        while(i<n && nums[i]< 0){
            i++;
        }
        int zereo = i;
        while(zereo < n &&  nums[zereo] == 0){
            zereo++;
        }
        cout << "i= " << i << " zero= " << zereo << endl;
        return max(i, n-zereo);
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}