#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        isVisited.resize(n + 1, 0);
        for(int i = 0 ; i< edges.size(); i++){
            int start = edges[i][0];
            int end = edges[i][1];
            u_map[start].push_back(end);
            u_map[end].push_back(start);
        }

        // auto it = u_map.begin();
        // while(it != u_map.end()){
        //     cout << it->first << " | ";
        //     for(int i = 0; i< it->second.size(); i++){
        //         cout<<  it->second[i] << " "; 
        //     }
        //     cout << endl;
        //     it++;
        // }
        
        vector<int>temp;
        for(int i =1; i <= n ;i++){
            for(int j = i+ 1; j <= n; j++){
                temp.clear();
                isVisited.clear();
                isVisited.resize(n + 1, 0);
                // cout << "i= " << i << " j= " << j << endl;
                DFS(i, j, i, temp);
            }
        }

        int resu = 0;
        int times = 0;
        set<vector<int>>myset;
        for(int i = 0; i< resuAllPatch.size();i++){
            times = 0;
            vector<int>temp =resuAllPatch[i];
            sort(temp.begin(),temp.end());
            // MyPrintOne(temp); 


            if(myset.find(temp) != myset.end()){
                continue;
            }else{
                myset.insert(temp);
            }
            
            

            for(int j = 0; j< temp.size();j++){
                if(isVailNum(temp[j])){
                    // cout << "temp[j]=  " << temp[j] << endl;
                    times++;
                } 
                if(times >= 2) break;
            }
            if(times == 1){
                // MyPrintOne(temp); 
                resu++;
            } 
            
        }
        cout << "resu= " << resu << endl;
        return resu;

    }


    // 判断一个数是否为质数
    bool isVailNum(int num)
    {
        if(num == 1) return false;
        if(num == 2) return true;
        for(int i =2; i<= num/2 + 1; i++){
            if(num % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    void DFS(int start, int end, int cur, vector<int>&temp)
    {
        // cout << "DFS" << " start " << start  << " end " << end << " cur= " << cur << endl;
        if(cur == end){
            temp.push_back(cur);
            //

            resuAllPatch.push_back(temp);
            // cout << "start= " << start <<  " end= " << end <<  " cur= " << cur << endl;
            // MyPrintOne(temp);
            // cout << "-++++end++++-" << endl;

            temp.pop_back();
            
            
            return;
        }
        
        
        // cout << "isVisited end"  << endl;
        if(isVisited[cur] == true) return;

        vector<int>neigh = u_map[cur];
        
        // MyPrintOne(temp);

        
        
        isVisited[cur] = true;
        temp.push_back(cur);

        for(int i = 0; i< neigh.size(); i++){
            // temp.push_back(neigh[i]);
            // isVisited[neigh[i]] = true;
            DFS(start, end, neigh[i], temp);
            // temp.pop_back();
        //    isVisited[neigh[i]] = false;
        }
        isVisited[cur] = false;
        temp.pop_back();
        
            
        
    }

private:
    unordered_map<int,vector<int>> u_map; // 邻接表
    vector<int>oneResu;
    vector<vector<int>>resuAllPatch;
    vector<int>isVisited;
};

int main()
{
    Solution s1;
    int n = 4;
    vector<vector<int>>edges  = {{1,2},{4,1},{3,4}};
    s1.countPaths(n, edges);

    
    

    cout << "hell22o" << endl;
    return 0;
}