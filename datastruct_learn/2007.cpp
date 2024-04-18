#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 ==1) return {};

        sort(changed.begin(),changed.end());
        
        reverse(changed.begin(),changed.end());
        // MyPrintOne(changed);

        vector<int>resu;
        while(changed.size() != 0){
            // sort(changed.begin(),changed.end());
            // reverse(changed.begin(),changed.end());

            auto it = changed.begin();
            int cur_val = *it;
            // cout << "cur_val "<< cur_val << endl;
            if(cur_val % 2== 1){ // 奇数
                return {};
            }else{ // 偶数
                int half = cur_val / 2;
                auto half_indexx=  find(changed.begin(),changed.end(), half);
                if(half_indexx == changed.end()) return {};
                resu.push_back(*half_indexx);
                // cout << "push "<< *half_indexx << endl;

                changed.erase(half_indexx);
                auto val_index= find(changed.begin(),changed.end(), cur_val);
                if(val_index != changed.end()){
                    changed.erase(val_index);
                }
                
            }

        }
        sort(resu.begin(),resu.end());
        // MyPrintOne(resu);
        return resu;
    }
private:
    
    
};
 

int main()
{
    Solution s1;
    vector<int> changed = {1,3,4,2,6,8};
    s1.findOriginalArray(changed);

    // multiset<int>meset;
    // meset.insert(1); meset.insert(1); meset.insert(12);
    // cout << "mesetsize= " << meset.size() << endl;
    // meset.erase(1);

    // cout << "mesetsize= " << meset.size() << endl;



    cout << "hell22o" << endl;
    return 0;
}