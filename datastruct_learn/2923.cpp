#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int N = grid.size();
        for(int i = 0; i < N; i++){
            if(isValild(grid, i)){
                return i;
            }
        }  
        return 0; 
    }
private:
    bool isValild(vector<vector<int>>& grid, int i )
    {   
        for(int k = 0; k < grid.size(); k++){
            if(k == i) continue;
            if(grid[i][k] == 0){
                return false;
            }
        }
        return true;

    }
};
 

int main()
{
    
    cout << "hell22o" << endl;
    return 0;
}