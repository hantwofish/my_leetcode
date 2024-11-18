#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class BinSearch{
public:
    int search(vector<int>&nums, int target)
    {
        int left = 0; 
        int right = nums.size() -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid]== target){
                return mid;
            }else if(nums[mid] >  target){
                right = mid -1;
            }else if(nums[mid] <  target){
                left = mid + 1;
            }
        }

        return -1;
    }


};

// 二分法
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        composition_temp = composition;
        stock_temp = stock;
        cost_temp = cost;


        int  leftbound = 1;
        int  rightbound = 2e8;
        int  curNumber = 0;
        int  resu = 0;

        
        while( leftbound <= rightbound){
            curNumber = (leftbound + rightbound) /2;
            // cout << "leftbound= " << leftbound << " rightbound " << rightbound << " curNumber=" << curNumber << endl;
            bool isVaild = false;

            for(int i= 0; i < k; i++) { // 遍历每个机器
                if( needCost(n,k, i , curNumber) <= budget ){ // 当前数值过小
                    resu = max(resu, curNumber) ;
                    isVaild = true;
                    break;
                }
            }
            if(isVaild){ // 取右边的
                leftbound = curNumber + 1;
            }else{
                rightbound = curNumber - 1;
            }
        }


        return resu;
    }
private:
    long long needCost(int n , int k, int machine_index, int max_type)
    {
        vector<long long>needNume(n, 0);// 每种类型需要的金属
        for(int i = 0; i< n; i++){ // 第i 类金属
            long long needcost_temp = (long long)max_type * (long long)composition_temp[machine_index][i];
            needNume[i] = max((long long)0, needcost_temp - (long long)stock_temp[i] );
        }
        long long needCost = 0;
        for(int i = 0; i < n; i++){
            needCost += ((long long)cost_temp[i] * (long long)needNume[i]);
        }
        return needCost;
    }
private:
    vector<vector<int>> composition_temp;
    vector<int> stock_temp; 
    vector<int> cost_temp;

};




int main()
{
    Solution s1;
    // int n = 3, k = 2, budget = 15;
    // vector<vector<int>> composition = {{1,1,1},{1,1,10}};
    // vector<int>stock = {0,0,100};
    // vector<int>cost = {1,2,3};

    int n = 2, k = 3, budget = 10;
    
    vector<vector<int>>  composition = {{2,1},{1,2},{1,1}}; 
    vector<int>stock  = {1,1}; 
    vector<int> cost = {5,5};


    int resu = s1.maxNumberOfAlloys(n, k, budget, composition, stock, cost);

    

    cout << "resu" << resu << endl;
    return 0;
}