#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<set>
#include<unordered_set>

#include<map>
#include<unordered_map>
#include<stack>
#include<queue>

using namespace std;

class Solution{
public:
    vector<string> mainCal(int N)
    {
        vector<int>nums;
        nums.resize(N,0);
        for(int i = 0;i < N; i++){
            nums[i] = i+1;
        }
        int vaildNum = 0;
        do{
            if(vaildNum >= 20){
                break;
            }

            if(  (IsVaild(nums)  ) ){
                vaildNum ++;
                Prinit(nums);
            }


        }while(next_permutation(nums.begin(), nums.begin()+ N));
        return {};
    }
    bool IsVaild(vector<int>&tmp)
    {
        int number = 1;
        stack<int>stk;
        for(int i = 0; i < tmp.size();i++){
            while(stk.empty() || stk.top() < tmp[i]){
                stk.push(number);
                number++;
            }
            if(stk.empty() || stk.top() != tmp[i]){
                return false;
            }
            stk.pop();
        }

        return true;

    }
    void Prinit(vector<int>&nums)
    {
        for(int i =0; i < nums.size();i++){
            cout << nums[i] ;
        }
        cout << endl;

    }
public:
};

int main()
{
    Solution s1;
    int N = 4;
    // cin >> N;
    vector<string>resu = s1.mainCal(N);
    for(int i = 0; i < resu.size();i++){
        cout << resu[i] << endl;
    }
    return 0;
}