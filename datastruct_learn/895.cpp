#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class FreqStack {
public:
    FreqStack() {

    }
    
    void push(int val) {
        stk.push(val);
        mp[val]++;
    }
    
    int pop() {
        stack<int>stk_temp;
        int key = stk.top();
        int maxTimes = getMaxQueKey();
        cout << "maxTimes= " << maxTimes << endl;
        while(!stk.empty()){
            if(mp[stk.top()] == maxTimes){
                key = stk.top();
                stk.pop();
                break;
            }else{
                int top_val = stk.top();
                stk.pop();
                stk_temp.push(top_val);
            }
        }

        while(!stk_temp.empty()){
            int it = stk_temp.top();
            stk_temp.pop();
            stk.push(it);
        }
        mp[key]--;
        return key;
    }

private:
    int getMaxQueKey()
    {
        auto it = mp.begin();
        int tiems = it->second;
        while(it != mp.end()){
            if( it->second > tiems){
                tiems = it->second;
            }
            it++;
        }
        return tiems;

    }
private:
    unordered_map<int,int>mp;// <key, 次数>
    stack<int>stk;
};
 

int main()
{
    
    cout << "hell22o" << endl;
    return 0;
}