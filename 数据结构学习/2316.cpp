#include"../STLCOMMON.h"

using namespace std;



class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        if(edges.empty()){
            return (n*(n-1))/2;
        }


        UnionFind uf(n);
        for(int i = 0; i < edges.size(); i++){
            uf.unionNode(edges[i][0], edges[i][1]);
        }
        // uf.PrintFather();
        for(int  i =0 ; i< n; i++){
            cout << "i= " << i << " fat= " << uf.find_fa(i) << endl;
        }
        long long resu = 0;
        for(int i= 0 ; i< n; i++){
            for(int j = i +1; j < n; j++ ){
                cout << "i= " << i << " j= " << j << " "<< uf.find_fa(i) << " "<< uf.find_fa(j) << endl;
                if(uf.find_fa(i) != uf.find_fa(j)){
                    //  cout << "i= " << i << " j= " << j << " "<< uf.find_fa(i) << " "<< uf.find_fa(j) << endl;
                    resu++;
                }
            }
        }

        
        return resu;
    }
};

int main()
{
    Solution s1;
    int n = 3;
    vector<vector<int>>edges = {{0,1},{0,2},{1,2}};
    long long resu = s1.countPairs(n, edges);
    cout << "resu= " << resu << endl;


    

    return 0;

}