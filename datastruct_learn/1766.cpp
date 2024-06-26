#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        return {};
    }
    bool isDIS(int a, int b)
    {
        for(int i = 2; i <= min(a,b); i++){
            if(a % i == 0 && b % i == 0){
                return false;
            }
        }
        return true;
    }
private:

}; 

int main()
{
    Solution s1;
    bool flag = s1.isDIS(3,5); 
    cout << flag << endl;
    
    cout << "hell22o" << endl;
    return 0;
}