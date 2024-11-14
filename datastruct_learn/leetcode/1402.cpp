#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int resu = INT32_MIN;
        for(int i= 0 ; i< satisfaction.size(); i++){
            resu = max(resu, calSum(satisfaction, i));
            cout << "i= " << i << " sum= " << resu << endl;
        }
        if(resu < 0) resu = 0;
        cout << "resu= " << resu << endl;
        return resu;

    }
    int calSum(vector<int>& satisfaction, int cur_i)
    {   
        int cur_time = 1;
        int sum  = 0;
        while(cur_i < satisfaction.size()){
            sum = sum + satisfaction[cur_i] * cur_time;

            cur_i++;
            cur_time++;
        }
        return sum;
    }
}; 

int main()
{
    vector<int>nums = {-1,-4,-5};
    Solution s1;
    s1.maxSatisfaction(nums);
    cout << "hell22o" << endl;
    return 0;
}