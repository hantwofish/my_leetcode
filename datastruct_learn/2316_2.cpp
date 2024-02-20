#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        if(edges.size()==0){
            long long resu = 0;
            resu = (long long)n * (long long)(n -1) /2;
            return resu;
        }
        UnionFind u1(n);
        // 合并操作
        for(int i= 0; i< edges.size(); i++){
            u1.unionNode(edges[i][0], edges[i][1]);
        }

        unordered_map<int, int>umap;
        // 更新每个节点的父亲
        for(int i= 0; i< n; i++){
            u1.father[i] = u1.find_fa(i);
            umap[u1.father[i]]++; // 每个祖先的个数
        }
        
        long long resu =0; 
        vector<int>father_times;
        auto it = umap.begin();
        while(it != umap.end()){
            father_times.push_back(it->second);
            it++;
        }   
        // MyPrintOne(father_times);
        for(int i= 0; i< father_times.size(); i++){
            for(int j = i+1; j< father_times.size(); j++){
                long long temp = (long long)father_times[i] * (long long)father_times[j];
                resu += temp;
            }
            
        }
        return resu;
    }
};
int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}