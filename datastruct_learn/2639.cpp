#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        if(grid.empty()) return {};
        vector<vector<string>> vecStr(grid.size(), vector<string>(grid[0].size(), ""));
        for(int i= 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                vecStr[i][j] = to_string(grid[i][j]);
            }
        }
        int N= grid.size();
        int M = grid[0].size();
        vector<int>vec;
        for(int j = 0; j< M; j++){
            int temp = 0;
            for(int i = 0; i < N;i++){
                
                temp = max(temp, (int)(vecStr[i][j].length()));
            }
            vec.push_back(temp);
        }
        MyPrintOne(vec);
        return vec;
    }
}; 

int main()
{
    vector<vector<int>> grid = {{-15,1,3},{15,7,12},{5,6,-2}};
    Solution s1;
    s1.findColumnWidth(grid);
    
    cout << "hell22o" << endl;
    return 0;
}