#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
#define maxn 10

int Fmax[maxn][10];

class Solution{
public:
    int calMaxArray(int& n, vector<int>&nums)
    {

        return 0;
    }
};

class ST {
public:
    ST(int num){
        n = num;
        k = log2(n);
        F.resize(n+1, vector<int>(k, 0));
    }
    void ST_create(vector<int>&array)
    {
        for(int i = 1; i<= n; i++){
            F[i][0]= array[i];
        }
        for(int j = 1; j <= k;j++){
            for(int i = 1; i <= n -(1<<j)+1; j++){
                F[i][j] = max(F[i][j-1], F[i+(1<<(j-1))][j-1]);
            }
        }
        MyPrintTwo(F);
    }
    int ST_Query(int left, int right)
    {
        int k = log(right - left +1);
        return max(F[left][k], F[right-(1<<k)+1][k]);
    }

private:
    int n;
    int k ;
    vector<vector<int>>F;
};  


int main()
{
    Solution s1;
    // s1.calMaxArray();
    vector<int>nums={0,100,3,45,6,9};
    ST st(nums.size());
    st.ST_create(nums);
    
    

    cout << "hell22o" << endl;
    return 0;
}


class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */