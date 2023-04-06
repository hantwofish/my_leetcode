#include"../STLCOMMON.h"

using namespace std;

bool CMP(int A, int B, int MID)
{
    if(abs(A -MID) > abs(B-MID)){
        return true;
    }
    if((abs(A -MID) == abs(B-MID)) && (A-B)){
        return true;
    }
    return false;
}

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        
        int N = arr.size();
        sort(arr.begin(),arr.end());
        MID = arr[(N-1)/2];
        MyPrintOne(arr);
        sort(arr.begin(),arr.end(),greater<int>());
        MyPrintOne(arr);

        vector<int>resu;
        vector<int> distance;
        distance.resize(N , 0);
        int i = 0, j = N-1, maxNum = k;
        while( maxNum > 0){
            if( abs(arr[i] - MID) >= abs(arr[j] - MID)){
                resu.push_back(arr[i]);
                i++;
            }else{
                resu.push_back(arr[j]);
                j--;
            }
            maxNum--;
        }
        MyPrintOne(resu);


        return resu;

    }
public:
    int MID = 0;
};

int main()
{
    Solution s1;
    vector<int> arr= {1,1,3,5,5};
    int k = 2;
    s1.getStrongest(arr,k);

    cout << "A " << endl;
    return 0;
}