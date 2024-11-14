#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std; 

class Solution {
public:
    int checkRecord(int n) {
        int N = 3;
        for(int i= 0; i< N; i++){
            vector<int>temp;
            vector<int>visited;
            visited.resize(temp.size(), 0);
            backtring(N, i, temp, visited, n);
        }
        print_vec(my_set);

        cout << "main resu= " << resu << endl;
        return resu;
    }
    void backtring(int N, int cur_index, vector<int>&temp, vector<int>&visited, int len)
    {   
        if(temp.size()== len){
            // print_vec(temp);
            // MyPrintOne(temp);
            my_set.insert(temp);
            return;
        }
        // if(visited[cur_index] == 1){
        //     return;
        // }
        temp.push_back(cur_index);
        // visited[cur_index] = 1;
        for(int i = 0; i< N; i++){
            backtring(N, i, temp, visited, len);
        }
        temp.pop_back();
        // visited[cur_index] = 0;

    }
private:
    int resu = 0;
    set<vector<int>>my_set;
    void print_vec(set<vector<int>>&my_set)
    {
        string resu_temp = "";
        auto it = my_set.begin();
        while(it != my_set.end()){
            vector<int>temp = *it;
            resu_temp = "";
            for(auto i : temp){
                // cout << i << " ";
                resu_temp = resu_temp + to_string(i);
            }
            // cout << endl;
            cout << resu_temp << endl;
            if(isVaild(resu_temp)) {
                resu++;
            }
            it++;
        }
    }
    bool isVaild(string resu)
    {
        if(resu.find("111") != string::npos) {
            return false;
        }
        int a_num = 0;
        for(auto i: resu){
            if(i == '0'){
                a_num++;
                if(a_num >= 2){
                    return false;
                }
            }
        }
        return true;

    }
};

int main()
{
    Solution s1;
 s1.checkRecord(1);
    
    

    cout << "hell22o" << endl;
    return 0;
}