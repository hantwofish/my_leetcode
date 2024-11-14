#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

/* 1. a.first < b.first 2. a.second < b.second    */
bool CMP(pair<int,int>& a, pair<int,int>& b)
{
    if(a.first < b.first){
        return true;
    }else if( a.first == b.first){
        return a.second < b.second;
    } else {
        return false;
    }
    return true;
}

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int times = 0;
        for(int i =0 ; i< ranges.size(); i++){
            vec.push_back({ranges[i][0], ranges[i][1]});
        }
        sort(vec.begin(), vec.end(), CMP);
        for(int i =0 ; i< vec.size(); i++){
            cout << vec[i].first << " " << vec[i].second << endl;
        }

        stack<pair<int,int>>stk;
        for(int i = 0; i< vec.size(); i++){
            if(stk.empty()){
                stk.push(vec[i]);
                continue;
            }
            auto stk_top = stk.top();
            auto cur_val = vec[i];
            int front_i = stk_top.first;
            int front_j = stk_top.second;
            int beind_i = cur_val.first;
            int beind_j = cur_val.second;
            printf("(%d,%d) -> (%d,%d) \n", front_i, front_j, beind_i, beind_j);
            if(beind_j == front_j ){ 
                front_i = min(front_i, beind_i);
                stk.pop();
                stk.push({front_i, front_j});
                printf("    merge= %d,%d \n",front_i, front_j);

            }else if(beind_j > front_j ){
                if(beind_i <= front_j){ // 相交
                    stk.pop();
                    stk.push({min(front_i,beind_i), max(front_j,beind_j)});
                    printf("    merge= %d,%d \n",min(front_i,beind_i), max(front_j,beind_j));
                }else{ // 不 相交
                    stk.pop();
                    cout << "pop= " << front_i  << " " << front_j << endl;
                    times++;
                    stk.push({beind_i, beind_j});
                    printf("   push = %d,%d \n",beind_i, beind_j);
                }
            }
        }

        cout << "stk.size= " << stk.size() << endl;
        while(!stk.empty()){
            times++;
            cout << "pop= " << stk.top().first << " " << stk.top().second << endl;
            stk.pop();
            
        }
        cout << "times = " << times << endl;
        return fastPow(2, times, 1e9 + 7);

    }
    long long fastPow(long long x, long long n, long long mod) 
    {
        long long res = 1;
        for (; n != 0; n >>= 1) {
            if (n & 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
        }
        return res;
    }
private:    
    vector<pair<int,int>>vec;
};

int main()
{
    Solution s1;


    // s1.calMaxArray();
    // vector<vector<int>> ranges ={{6,10},{5,15}};
    vector<vector<int>> ranges ={{1,3},{10,20},{2,5},{4,8}};
    // vector<vector<int>> ranges= {{34,56},{28,29},{12,16},{11,48},{28,54},{22,55},{28,41},{41,44}};
    int resu = s1.countWays(ranges);
    cout << "resu= " << resu << endl;
    

    cout << "hell22o" << endl;
    return 0;
}