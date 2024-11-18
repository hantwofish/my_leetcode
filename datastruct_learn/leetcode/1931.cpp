#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution1 { //DFS超时
public:
    int colorTheGrid(int m, int n) {
        numsize = m * n;
        figure.resize(m, vector<int>(n, 0));

        backTracing(m,n , 0, 0);
        cout << "resu= " << resu << endl;
        return 0;

    }
    void backTracing(int m, int n, int cur_row, int cur_col)
    {
        int curNode = (cur_row +1  -1) * n + (cur_col + 1) - 1;
        if(curNode >= numsize){
            // resu++;
            resu = (resu + 1) % MOD_NUM;
            // cout << "resu= " << resu << " cur_row= " << cur_row << " cur_col= " << cur_col << endl; 
            return;
        }

        for(int i = 1; i<= 3; i++){
            // 是否可以放置 1
            if( (cur_row - 1 < 0   ||  figure[cur_row - 1][cur_col] != i) && 
                (cur_row + 1 >= m  ||  figure[cur_row + 1][cur_col] != i) &&
                (cur_col - 1 < 0   ||  figure[cur_row][cur_col - 1] != i) && 
                (cur_col + 1 >= n  ||  figure[cur_row][cur_col + 1] != i)  ){
                    figure[cur_row][cur_col] = i;
                    if(cur_col + 1 >= n){
                        backTracing(m, n, cur_row + 1, 0);
                    }else{
                        backTracing(m, n, cur_row, cur_col + 1);
                    }       
                    figure[cur_row][cur_col] = 0;
            }
        }

    }
private:
    int resu = 0;
    const int MOD_NUM = 1e9+7;
    int numsize =0 ;
    vector<vector<int>>figure; // 用于存储当前位置的颜色 123 红绿蓝
};


// DFS 超时
class Solution2 {
public:
    int colorTheGrid(int m, int n) {
        firg_row_num.resize(m, -1);
        N = n;
        M = m;
        init();

        DFSBackTring(m,n,0);
        cout << "resutimes= " << resutimes << endl;
        return resutimes;
    }
    void DFSBackTring(int m, int n, int cur_row )
    {
        if(cur_row >= m){
            // MyPrintOne(firg_row_num);
            // resutimes++;
            resutimes = (resutimes + 1) % MOD_NUM;
            return;
        }   

        if(cur_row == 0){
            for(int i= 0; i< pow(3,n); i++){
                // if(isVailPut(transform(i, 3)) == false) continue;
                if(vailsSet.find(binString[i]) == vailsSet.end()) continue;

                firg_row_num[cur_row] = i;
                DFSBackTring(m,n, cur_row + 1);
                firg_row_num[cur_row] = -1;
            }
            return;
        }

        for(int i = 0; i< pow(3,n); i++){
            // if(isVailPut(transform(i, 3)) == false) continue;
            if(vailsSet.find(binString[i]) == vailsSet.end()) continue;
            // cout << "firg_row_num[cur_row-1]= " << firg_row_num[cur_row-1] << endl;
            if( isVaid(binString[i] , binString[firg_row_num[cur_row-1]] ) ){ // 可以放置
                firg_row_num[cur_row] = i;
                DFSBackTring(m,n, cur_row + 1);
                firg_row_num[cur_row] = -1;
            }
        }
    }
private:
    vector<int>firg_row_num;
    int resutimes =0;
    int N ,M;
    unordered_map<int,string> binString; // 存储十进制数的三进制形式
    set<string>vailsSet;
    const int MOD_NUM = 1e9+7;

    void init()
    {
        for(int i= 0; i< pow(3,N); i++){
            string num = transform(i, 3);
            binString[i] = num;
            if(isVailPut(num)){
                vailsSet.insert(num);
            }
        }
    }


    bool isVailPut(string a)
    {
        for(int i= 1; i< a.size(); i++){
            if(a[i]==a[i-1]){
                return false;
            }
        }
        return true;
    }
    bool isVaid(string a, string b)
    {
        for(int i= 0; i< a.size(); i++){
            if(a[i] == b[i]) return false;
        }
        return true;
    }
public:
    // 进制转换 10 ->  3
    string transform(int num, int MOD)
    {
        string resu = "";
        int temp = num;
        while(num){
            int mod_num = num % MOD;
            resu += to_string(mod_num);
            num = num / MOD;
        }
        reverse(resu.begin(),resu.end());
        int diff = N - resu.size();
        while(diff > 0){
            resu = "0" + resu;
            diff--;
        }

        // cout << temp << " -> " << resu << endl;
        return resu;
    }
    // 进制转换 3 ->  10
    int transTO(string num, int MOD)
    {
        int resu = 0;
        int index = 0;
        reverse(num.begin(), num.end());
        while(index < num.length())
        {
            resu = resu + (num[index] - '0') * pow(MOD, index);
            index++;
        }
        // cout << num <<" -> " << resu << endl;
        return resu;
    }
};

class Solution {
public:
    int colorTheGrid(int m, int n) {
        init(m,n);
        vector<vector<long long>>dp(N, vector<long long>(maxMask,0));
        for(int j = 0; j< N; j++){  // 列数
            for(int new_mask = 0; new_mask < maxMask; new_mask++){
                // if(vailsSet.find(binString[new_mask]) == vailsSet.end()) continue;
                if(isOk[new_mask] == false ) continue;
                if( j == 0 ){
                    dp[j][new_mask]++;
                }else{
                    for(int old_mask = 0; old_mask < maxMask; old_mask++){
                        // if(vailsSet.find(binString[old_mask]) == vailsSet.end()) continue;
                        if(isOk[old_mask] == false ) continue;
                        if(isVaid(binString[new_mask], binString[old_mask]) == false) { // 两列之间有相同的不可以放置
                            continue;
                        }
                        dp[j][new_mask] += dp[j-1][old_mask];
                        dp[j][new_mask] = dp[j][new_mask] % MOD_NUM;
                    }
                }
            }
        }
        long long resutimes =0;
        for(int mask = 0; mask < maxMask; mask++){
           resutimes = (resutimes + dp[N-1][mask]) % MOD_NUM;
        }
        cout << "resu= " << resutimes << endl;
        return resutimes;
    }
    void init(int m, int n)
    {
        M = m;
        N = n;
        maxMask = pow(3,M);
        isOk.resize(maxMask,0);
        for(int i= 0; i< maxMask; i++){
            string num = transform(i, 3);
            binString[i] = num;
            if(isVailPut(num)){
                vailsSet.insert(num);
                isOk[i] = true;
            }
        }

    }
private:
    int N,M;
    set<string>vailsSet;
    vector<bool>isOk;
    
    unordered_map<int,string> binString; // 存储十进制数的三进制形式
    int maxMask = 0;
    const int MOD_NUM = 1e9+7;

    bool isVailPut(string a)
    {
        for(int i= 1; i< a.size(); i++){
            if(a[i]==a[i-1]){
                return false;
            }
        }
        return true;
    }
    bool isVaid(string a, string b)
    {
        for(int i= 0; i< a.size(); i++){
            if(a[i] == b[i]) return false;
        }
        return true;
    }
    
    string transform(int num, int MOD)
    {
        string resu = "";
        int temp = num;
        while(num){
            int mod_num = num % MOD;
            resu += to_string(mod_num);
            num = num / MOD;
        }
        reverse(resu.begin(),resu.end());
        int diff = M - resu.size();
        while(diff > 0){
            resu = "0" + resu;
            diff--;
        }

        // cout << temp << " -> " << resu << endl;
        return resu;
    }
};

int main()
{
    Solution s1;
    s1.colorTheGrid(1,2);
    
    return 0;
}