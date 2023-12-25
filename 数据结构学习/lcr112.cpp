#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        N = matrix.size();
        M = matrix[0].size();
        // cout << "n= " << N << " m= " << M << endl;
        is_visited.resize(N, vector<int>(M,0));
        for(int i= 0; i< N; i++){
            for(int j = 0; j< M; j++){
                temp.clear();
                is_visited.resize(N, vector<int>(M,0));

                dfs(matrix, i,j);
            }
        }
       
        // int maxlen = 0;
        // for(int i = 0; i< allResult.size();i++){
        //     int veclen = allResult[i].size();
        //     maxlen = max(maxlen, veclen);
        // }
        cout << "maxlen= " << outresu << endl;
        return outresu;
    }
    void dfs(vector<vector<int>>& matrix, int cur_i, int cur_j)
    {
        if(is_visited[cur_i][cur_j]) return;
        if(index_is_vaild(cur_i,cur_j) == false) return;

        temp.push_back(matrix[cur_i][cur_j]);
        is_visited[cur_i][cur_j] = true;
        // cout << "temp = " << matrix[cur_i][cur_j] << endl;
        for(int i= 0; i< 4; i++){
            int index_i = cur_i + digto[i][0];
            int index_j = cur_j + digto[i][1];
            // cout << "index_i= " << index_i << " index_y= " << index_j << " = " << index_is_vaild(index_i,index_j)  << endl;
            if(index_is_vaild(index_i,index_j)  && matrix[index_i][index_j] > matrix[cur_i][cur_j]){
                // cout << "index_i= " << index_i << " index_y= " << index_j << " val= " << matrix[index_i][index_j] << endl;
                dfs(matrix,index_i, index_j);
            }else {
                // allResult.push_back(temp);
                int veclen= temp.size();
                outresu =max(outresu, veclen);
            }  
        }

        temp.pop_back();
        is_visited[cur_i][cur_j] = false;


    }
    bool index_is_vaild(int i,int j)
    {
        if(i >=0 && i < N && j >=0 && j < M){
            return true;
        }
        return false;
    }
private:
    int N =0;
    int M =0;
    vector<int>temp;
    vector<vector<int>>is_visited;
    vector<vector<int>>allResult;
    vector<vector<int>>digto = {
        {0,1},{0,-1},{-1,0},{1,0}
    };
    int outresu =0;
};




int main()
{
    Solution s1;
    vector<vector<int>>matrix = {{9,9,4},{6,6,8},{2,1,1}};
    s1.longestIncreasingPath(matrix);

    

    cout << "hell22o" << endl;
    return 0;
}