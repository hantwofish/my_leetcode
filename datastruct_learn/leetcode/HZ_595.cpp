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
    vector<string>mainChain(int &N, vector<string>&nums, string &target )
    {
        stack<string> stk;
        stk.push(nums[0]);
        for(int i =1 ;i< nums.size();i++){
            string tmp = nums[i];
            if(tmp == "return"){
                stk.pop();
            }else{
                // cout <<" str= " << tmp << endl;
                stk.push(tmp);
            }
            if(tmp ==target){
                break;
            }
        }
        vector<string> outPut;
        auto it = stk.top();
        while(!stk.empty()){
            it = stk.top();
            outPut.push_back(it);
            stk.pop();
        }
        if(find(outPut.begin(),outPut.end(),target) == outPut.end()){
            return {"NOT REFERENCED"};
        }
        // MyPrintOne(outPut);
        reverse(outPut.begin(), outPut.end());
        // MyPrintOne(outPut);



        return outPut;
    }


public: 

};

void GetData(int &N, vector<string>&nums, string &target)
{
    cin>> N;
    nums.clear();
    target = "";
    for(int i = 0; i< N;i++){
        string tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    cin>> target;
}

int main()
{
    Solution s1;
    int N = 5;
    vector<string>nums= {
        "fun1()",
        "fun2()",
        "return",
        "fun3()",
        "fun4()"
    };
    string targr = "fun7()";
    GetData(N, nums, targr);
    vector<string> resu ; 
    resu = s1.mainChain(N, nums, targr);

    cout << resu[0];
    for(int i = 1; i < resu.size();i++){
        cout << "->" << resu[i];
    }
    cout << endl;
    return 0;
}