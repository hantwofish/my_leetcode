#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string s_Tem  = s;
        int len = s.length();
        int one_Num = 0;
        for(int i= 0; i< len; i++){
            if(s[i] == '1') one_Num++;
        }
        s.clear();
        s.resize(len, '0');
        if( one_Num == 0){
            return s_Tem;
        }else if(one_Num == 1){
            s[len-1] ='1';
            return s;
        }else if(one_Num > 1){
            s[len-1] = '1';
            one_Num--;
            int indx = 0;
            while(one_Num> 0){
                s[indx] = '1';
                indx++;
                one_Num--;
            }
            return s;
        }   
        return s;
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}