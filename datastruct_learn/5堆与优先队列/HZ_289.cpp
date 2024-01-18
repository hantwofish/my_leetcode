#include"../../STLCOMMON.h"

using namespace std;
class Solution{
public:
    int SolvePro(int N,int M ,vector<int>&nums)
    {
        return 0;
    }
    
public:
    
};

void GetData(int &N, int &M, vector<int>&nums)
{
    cin >> N >> M;
    nums.clear();
    int tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        nums.push_back(tmp);
    }
    MyPrintOne(nums);
}

int main()
{
    int N = 5;
    int M= 2;
    vector<int>nums= {2 ,-3 ,2 ,-1, 0};
    // GetData(N,M,nums);
    Solution s1;
    int resu = s1.SolvePro(N,M,nums);
    cout << "resu= " << resu << endl;

    return 0;


}