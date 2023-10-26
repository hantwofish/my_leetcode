#include"../STLCOMMON.h"

using namespace std;

class Solution {
public:
    int punishmentNumber(int n) {
        int resu = 0;
        for(int i = n; i <= n ; i++){
            string str = to_string(i*i);
            if(check(str, 0, 0,i)){
                cout << "i = " << i << endl;
                resu += (i*i);
            }
        }
        // cout << "resu= " << resu << endl;
        return resu;
        

    }

    // 递归函数只看当前层的功能
    bool check(string str, int curIndex, int totalSum, int target)
    {
        cout << "one str= " << str << " cur= " << curIndex << " totalSum= " << totalSum << " TARGET= " << target << endl;
        if( curIndex == str.size() ){
            cout << "      return index = " << curIndex << endl;
            return totalSum == target;
        }

        // totalSum 为[0, curIndex-1] 各种排列后的结果
        int sum = 0;
        for(int i = curIndex; i< str.size(); i++){
            sum = sum * 10 + (str[i] - '0');
            cout << "  i= " << i << " sum= " << sum << endl;
            if( check(str, i+1, sum + totalSum, target)){
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution s1;
    int n = 14;
    int resu = s1.punishmentNumber(n);
    cout << "resu= " << resu << endl;
    return 0;
}