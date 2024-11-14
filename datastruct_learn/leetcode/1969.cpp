#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int minNonZeroProduct_2(int p) {
        int A = (1 << p) -1;
        long long B = (1 << p ) -2;
        long long C = (1 << (p-1)) -1;
        
        cout << "A= "<< A << " B= " << B << " C= "<< C << endl;

        long long resu = 1;
        while(C > 0){
            resu = resu * B;
            while(resu > 1e9 + 7){
                resu -=  1e9 + 7;
            }
            C--;
        }
        cout << " resu= " << resu << endl;
        const long long temp = resu;
        cout << "temp =" << temp << endl;
        resu = 0;
        while(A > 0 ){
            resu += temp;
            while(resu > 1e9 + 7){
                resu -=  1e9 + 7;
            }
            A--;
        }

        cout << " output resu= " << resu << endl;
        return resu;

    }


    long long fastPow(long long x, long long n, long long mod) 
    {
        long long res = 1;
        for (; n != 0; n >>= 1) {
            if (n & 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
        }
        return res;
    }
    
    int minNonZeroProduct(int p) {
        if (p == 1) {
            return 1;
        }
        long long mod = 1e9 + 7;
        long long x = fastPow(2, p, mod) - 1;
        long long y = (long long) 1 << (p - 1);
        cout << "x= " << x << " y= " << y << endl;
        
        return fastPow(x - 1, y - 1, mod) * x % mod;
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    s1.minNonZeroProduct(3);
    
    

    cout << "hell22o" << endl;
    return 0;
}