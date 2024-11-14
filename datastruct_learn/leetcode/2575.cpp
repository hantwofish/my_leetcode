#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        resu.resize(word.size(), 0);
        MOD = m;
        while(MOD < UINT32_MAX) {
            MOD *= 10;
        }
        cout << "mod= " << MOD << endl;
        

        long long resu_temp = word[0] - '0';
        if(resu_temp % m == 0){
            resu[0]= 1;
        }

        for(int i =1; i< word.length(); i++){
            long long temp = word[i] - '0';

            // if(i == 0){
                // resu_temp =  temp;     
            // }else{
                resu_temp = resu_temp * 10  + temp;
            // }
            
            cout<< "i= " << i << " resu_temp = " << resu_temp << endl;

            while(resu_temp > MOD){
                resu_temp -= MOD;
            }

            if(resu_temp % m ==0 ){
                resu[i]= 1;
            }

            cout<< "i= " << i << " resu= " << resu[i] << endl;
        }
        MyPrintOne(resu);
        return resu;
    }
private:
    vector<int>resu;
    long long MOD = 1;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
   string  word = "8917171717276217174131";
   int m = 17;
   s1.divisibilityArray(word, m);

   cout << "MAX= "<< UINT64_MAX << endl;
    

    cout << "hell22o" << endl;
    return 0;
}