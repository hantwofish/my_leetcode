#include"../STLCOMMON.h"
using namespace std;


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {


        return 0;
    }
};


int main()
{
    Solution s1;
    int n = 6;
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    int resu =s1.makeConnected(n, connections);
    cout << "resu = " << resu << endl;
    return 0;

}