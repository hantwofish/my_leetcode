#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

#define VAL_INDEX 0
#define TIEMS_INDEX 1
#define TIME_INDEX 2

class LFUCache {
public:
    LFUCache(int capacity) {
        N = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            mp[key] = {mp[key][0], (mp[key][1])+1, cur_time};
            // cout << "get key= " << key << " " << mp[key][0] << " " << mp[key][1]<< " " << mp[key][2] << endl; 
            cur_time++;
            return mp[key][0];
        }
        cur_time++;
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){ // 存在
            mp[key] = {value, mp[key][1]+1, cur_time};
            cur_time++;
            return ;
        }
        // 不存在
        if(mp.size() < N){ 
            mp[key] = {value, 1, cur_time};
            cur_time++;
            return ;
        }else { // 需要删除使用次数最少的
            int erase_inde = getMinxIndex();
            // cout << "erase_inde= " << erase_inde << endl;
            mp.erase(erase_inde);
            mp[key] = {value, 1, cur_time};
            cur_time++;
        }
        
        
        return ;


    }
    int getMinxIndex()
    {
        auto it = mp.begin();
        int key = it->first;
        int visited_times = it->second[1];
        int time = it->second[2];
        while(it != mp.end()){
                // cout << "key= " << it->first << " " << it->second[0] << " " << it->second[1]<< " " << it->second[2] << endl; 
            if(it->second[1] < visited_times){
                visited_times = it->second[1];
                time = it->second[2];
                key = it->first;
            }else if(it->second[1] == visited_times){
                if(it->second[2] < time){
                    visited_times = it->second[1];
                    time = it->second[2];
                    key = it->first;
                }
            }
            it++;
        }
        return key;
    }
private:
    unordered_map<int,vector<int>>mp;
    int N = 0;
    int cur_time = 0;
};

    // unordered_map<int,vector<int>>mp; //[val, visited_times, cur_time] 值，访问次数，时间 
    // int N = 0;
    // int cur_time = 0;

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */ 

int main()
{
    
    cout << "hell22o" << endl;
    return 0;
}