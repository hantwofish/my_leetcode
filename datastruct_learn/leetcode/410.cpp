#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        vector<int>splitArray;
        DFS(nums, 0, k, splitArray);
        return 0;
    }
    void DFS(vector<int>&nums,int cur_index,  const int k,  vector<int>&split_inde_array)
    {
        cout << "cur_index= " << cur_index <<   endl;
        if(split_inde_array.size() == k -1)  {
            one_resu_sum.push_back(calSumArray(nums,k, split_inde_array));
            MyPrintOne(split_inde_array);
            return;
        }
        
       
        split_inde_array.push_back(cur_index);
        cout << "push " << cur_index << endl;
        cur_index++;
        cout << "33 cur_index= " << cur_index  << endl;
        
        DFS(nums, cur_index, k, split_inde_array );
        split_inde_array.pop_back();
        
        // cur_index--;
        
        // MyPrintOne(split_inde_array);



    }
    int calSumArray(vector<int>&nums, int k, vector<int>&split_inde_array)
    {
        if(split_inde_array.size() != k -1){
            cout << "split err : size= " << split_inde_array.size() << endl;
            return -1;
        }
        vector<int>sumArry;
        int start_Index = 0;
        int end_Index = 0;
        for(int i = 0; i < split_inde_array.size(); i++){
            int end_Index =  split_inde_array[i];
            int tempSum = sumfromto(nums, start_Index, end_Index);
            sumArry.push_back(tempSum);
            start_Index = end_Index + 1;
        }
        sumArry.push_back(sumfromto(nums, start_Index, nums.size()-1));

        int sumresu = sumfromto(sumArry, 0, sumArry.size()-1);;

        return sumresu;

    }
    int sumfromto(vector<int>&nums, int begin, int end)
    {
        int resu = 0;
        for(int i=begin; i<= end; i++){
            resu += nums[i];
        }
        return resu;
    }
private:
    vector<int>one_resu_sum;
};



int main()
{
    Solution s1;
    vector<int>nums =  {7, 2,5, 10, 8};
    int k = 3;
    s1.splitArray(nums,k);

    

    cout << "end--" << endl;
    return 0;
}