#include"../STLCOMMON.h"
#include"../COMMONALO.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;



// N   进制转换
class Solution {
public:
    string baseNeg2(int n) {
        return numTN(n, -2);
    }
    string numTN(int num, int N)
    {
        cout << "numTN " << endl;
        string ans = "";

        if(num == 0) return "0";
        while(num != 0){
            int f = num % N;
            if(f == 0){
                cout << "0" << " ";
                ans = ans + "0";
            } else if(f < 0){
                // f 小于0 的为无效值
                f = f + abs(N);
cout << f << endl;
                if(f >= 10){
                    ans += ('0' + (f - 10));
                }else{
                    ans += ('0' + f);
                }               
                num = num -f; // 移除最后一个元素，为了可以进行整除
            } else{
cout << f << endl;
                if(f >= 10){
                    ans += ('0' + (f - 10));
                }else{
                    ans += ('0' + f);
                } 
                num = num - f; // 移除最后一个元素，为了可以进行整除
            }
            
            num = num / N;
        }
        reverse(ans.begin(), ans.end());
        cout <<"ans= " <<  ans << endl;
        return ans;

    }
};

int main()
{
    Solution s1;
    int num = 4;
    s1.baseNeg2(num);
    s1.numTN(num, 2);
    
    cout << "hell22o" << endl;
    return 0;
}