#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        for(auto i: nums){
            if(i% 2 == 0){
                mp[i]++;
            }
        }
        if(mp.size() <= 0) return -1;

        int key = mp.begin()->first;
        int val = mp.begin()->second;
        auto it = mp.begin();
        while(it != mp.end()){
            if(it->second > val){
                key = it->first;
                val = it->second;
            }else if(it->second == val){
                if(it->first < key){
                    key = it->first;
                    val = it->second;                   
                }
            }
            it++;
        }
        return key;
    }
private:    
    unordered_map<int,int>mp;
};
 

int main()
{
    
    cout << "hell22o" << endl;
    return 0;
}