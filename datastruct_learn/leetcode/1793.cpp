#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int maximumScore_2(vector<int>& nums, int k) {
        int resu =0;
        for(int i =k ; i >= 0; i--){
            for(int j = k; j< nums.size();j++){
                int min_num = INT32_MAX;
                for(int k =i; k<= j;k++){
                    min_num = min(min_num, nums[k]);
                }
                cout << "i= " << i<< " j= " << j << " min_num = " <<  min_num << " val=  " << min_num * (j - i +1) << endl;
                resu = max(resu, min_num * (j - i +1));

            }
        }
        cout << "resu= "<< resu <<endl;
        return resu;
    }   
    int maximumScore(vector<int>& nums, int k) {
        int resu = nums[k];
        int left = k;
        int right = k;
        int min_num = nums[k];

        while(left >=0 && right <= nums.size()){
            min_num = min(min_num, nums[left]);
            min_num = min(min_num, nums[right]);
            resu = max(resu, min_num * (right - left +1));


            if(left-1 >= 0 && right + 1 <= nums.size() ){
                if(nums[left-1] > nums[right +1]){
                    left--;
                }else{
                    right++;
                }
                
            } else if( left -1 >= 0 ){
                left--;
            } else{
                right++;
            }
            
        }
        cout << "resu= "<< resu <<endl;
        return resu;
    } 
};

int main()
{
    Solution s1;
    vector<int> nums = {6569,9667,3148,7698,1622,2194,793,9041,1670,1872};
    int k = 5;
    s1.maximumScore(nums, k);

    
    

    cout << "hell22o" << endl;
    return 0;
}