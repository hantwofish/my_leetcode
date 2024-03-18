#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        num_arry.resize(nums.size(), 0);
        for(int i= 0;i< nums.size(); i++){
            if(i == 0) num_arry[0]= nums[0];
            num_arry[i] = num_arry[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        left = max(0, left);
        int len = num_arry.size()-1;
        right = min(right, len);

        if(left == 0) return num_arry[right];

        return num_arry[right] - num_arry[left-1];

    }
private:
    vector<int>num_arry; // num_arry[i] = [0, i]
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}