#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int orig_size = coins.size();
        vector<int>sumResu = isSplited(coins, target);
        sumResu.push_back(0);
        for(auto val : sumResu){
            u_map[val] = true;
        }

        for(int cal_target = 1; cal_target <= target; cal_target++){
            // if(  find(coins.begin(), coins.end(), cal_target) != coins.end()) continue;
            // if(  find(sumResu.begin(), sumResu.end(), cal_target) != sumResu.end()) continue;
            if(u_map[cal_target] == true) continue;


            coins.push_back(cal_target);
            cout << "push " << cal_target << endl;
            int N = sumResu.size();
            for(int i = 0; i< N; i++){
                sumResu.push_back(sumResu[i] + cal_target);
                u_map[sumResu[i] + cal_target] = true;
            }
        }
        return coins.size()-orig_size;

    }
    vector<int> isSplited(vector<int>&coins, int target)
    {
        vector<vector<int>>resu;
        vector<int>temp;
        for(int start = 0 ; start < coins.size(); start++){
            temp.clear();
            dfs(coins, start, resu, temp);
        }
        // dfs(coins, 0, resu, temp);
        // MyPrintTwo(resu);
        
        vector<int>sumResu;
        for(int i= 0; i< resu.size(); i++){
            int temp_resu = 0;
            for(auto val : resu[i]){
                temp_resu += val;
            }
            sumResu.push_back(temp_resu);
        }
        return sumResu;

    }
    void dfs(vector<int>&coins, int cur_index, vector<vector<int>>&resu, vector<int>&temp)
    {
        if(cur_index >= coins.size()){
            return;
        }
        temp.push_back(coins[cur_index]);
        resu.push_back(temp);
        for(int j = cur_index + 1; j < coins.size(); j++ ){
            dfs(coins, j, resu, temp);
        }
        temp.pop_back();
    }
private:    
    unordered_map<int, bool>u_map;
};




int main()
{
    Solution s1;
    vector<int>coins= {100000};
    int target = 100000;
    s1.minimumAddedCoins(coins, target);
    
    

    cout << "hell22o" << endl;
    return 0;
}