#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        bitNum.resize(32,0);
        for(int i = 0; i< nums.size(); i++){
            string bin_str = int_to_bin(nums[i]);
            reverse(bin_str.begin(), bin_str.end());
            for(int j = 0 ; j < bin_str.length(); j++){
                if(bin_str[j] == '1'){
                    bitNum[j]++;
                }
                
            }
        }
        int resu_num = 0;
        for(int i = 0; i< bitNum.size(); i++){
            if(bitNum[i] >= k){
                cout << "i= "<< i << endl;
                resu_num += (pow(2, i));
            }
        }
        cout << "resu_num= " << resu_num << endl;
        return resu_num;
    }
private:
    vector<int>bitNum;
    string int_to_bin(int num)
    {
        string resu = "";
        int temp_num = num;
        while(num > 0){
            resu =  to_string(num % 2) + resu;
            num = num /2;
        }
        cout<< "num= " << temp_num << " " << resu << endl;
        return resu;
    }
};

int main()
{
    Solution s1;
    vector<int>nums = {7,12,9,8,9,15};
    int k =4;
    s1.findKOr(nums,k);
    
    

    cout << "hell22o" << endl;
    return 0;
}