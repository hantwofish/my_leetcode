#include"../STLCOMMON.h"

using namespace std;

class Solution{
public:
    int calMaxVal(vector<vector<int>>&nums)
    {
        int N = nums.size();
        vector<vector<int>>data(N,vector<int>(N,0));
        for(int i =0 ; i < nums.size(); i++){
            if(i == 0){
                data[0][0] =  nums[0][0];
                continue; 
            }
            for(int j = 0; j < nums[i].size(); j++){
                int left  = 0;
                int right = 0;
                if(  j-1 < 0){
                    left = 0;
                }else{
                    left = data[i-1][j-1];
                }

                if(  j < 0){
                    right = 0;
                }else{
                    right = data[i-1][j];
                }


                data[i][j]= max(left,right) + nums[i][j];
            }
        }
        MyPrintTwo(data);
        int resu = 0;
        for(int i = 0; i < data[data.size()-1].size(); i++){
            resu = max(resu, data[data.size()-1][i]);
        }
        cout << "resu= " << resu << endl;
    }
};

int main()
{

    vector<vector<int>> nums={
        {3},
        {9 ,5},
        {4 ,2 ,1},
        {3 ,4 ,9 ,6},
        {3 ,5 ,3 ,7 ,3},
       { 2 ,1 ,3 ,9 ,3 ,2}
    };
    Solution s1;
    s1.calMaxVal(nums);

    cout << "end" << endl;
    return 0;
}