#include"../STLCOMMON.h"
#include"../COMMONALO.h"



using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int>resu(2,0);
        if(mat.empty()) return {0,0};
        N = mat.size();
        M = mat[0].size();
        for(int i = 0; i< mat.size(); i++){
            for(int j = 0; j< mat[i].size();j++){
                if(isVaild(i-1,j)){
                    if(mat[i][j] < mat[i-1][j]){
                        continue;
                    }
                }
                if(isVaild(i+1,j)){
                    if(mat[i][j] < mat[i+1][j]){
                        continue;
                    }
                }
                if(isVaild(i,j-1)){
                    if(mat[i][j] < mat[i][j-1]){
                        continue;
                    }
                }
                if(isVaild(i,j+1)){
                    if(mat[i][j] < mat[i][j+1]){
                        continue;
                    }
                }
                return {i,j};

            }
        }
        return {0,0};
        
    }
    bool isVaild(int i, int j)
    {
        return (i>=0)&&(i<N)&&(j>=0)&&(j<M);

    }
public:
    int N = 0;
    int M = 0;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}