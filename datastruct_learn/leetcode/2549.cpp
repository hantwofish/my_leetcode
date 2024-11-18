#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int distinctIntegers(int n) {
        

        datable.insert(n);

        cout << "insert = " << n << endl;
        

        while(N>0){
            auto it = datable.begin();
            int setSize = datable.size();

            while(setSize > 0){
                int x = *it;
                for(int i=1; i <= n;i++){
                   if(x % i ==1){
                    datable.insert(i);
                    // cout << "push= " << i << endl;
                   } 
                }
                setSize--;
                it++;
            }

            N--;
        }
       
    //    cout << "size= " << datable.size() << endl;
        return datable.size();
    }
private:
    // int N = 1e9;
    int N = 1000;
    set<int>datable;
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    int n = 3;
    int resu = s1.distinctIntegers(n);
    cout << "resu= "<< resu << endl;
    
    

    cout << "hell22o" << endl;
    return 0;
}