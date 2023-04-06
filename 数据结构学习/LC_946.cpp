#include"../STLCOMMON.h"

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int pushIndex = 0;
        for(int i = 0; i < popped.size(); i++){
            while(stk.empty() || stk.top() != popped[i]){
                if(pushIndex >= pushed.size()){
                    break;
                }
                cout << "while i= " << i << " push index= " << pushIndex << "  push " << pushed[pushIndex] << endl;
                stk.push(pushed[pushIndex]);
                pushIndex++;
            }
            if( stk.empty() || stk.top() != popped[i] ){
                if(pushIndex < pushed.size()){
                    cout << " i= " << i << " push index= " << pushIndex << " push " << pushed[pushIndex] << endl;
                    stk.push(pushed[pushIndex]);
                    pushIndex++;
                }else{
                    cout << "Index= " << pushIndex << endl;
                    return false;
                }
            }
            cout << " i= " << i << " pop " << stk.top() << endl;
            stk.pop();

        }
        return true;

    }
};

int main()
{
    Solution s1;
    vector<int> pushed = {1,2,3,4};
    vector<int> popped = {2,1,3,4};
    bool flag = s1.validateStackSequences(pushed, popped);
    cout << "flag= "  << flag << endl;
    return 0;
}