#include"../STLCOMMON.h"

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        return {};

    }
};

int main()
{
    Solution s1;
    int n = 6;
    vector<vector<int>>edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    vector<int>resu = s1.sumOfDistancesInTree(n,edges);
    MyPrintOne(resu);
    cout << "------end---------" << endl;
    return 0;

}