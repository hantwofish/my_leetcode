#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) {
        N = capacity;
        cur_time = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        mp[key].second = cur_time;
        cur_time++;
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key] = make_pair(value, cur_time);
            cur_time++;
            return;
        }

        if(mp.size() < N){
            mp[key] = make_pair(value, cur_time);  
        }else{
            int erase_key = getMinKey();
            cout << "erase_key= " << erase_key << endl;
            mp.erase(erase_key);
            mp[key] = make_pair(value, cur_time);
        }


        cur_time++;
    }
    int getMinKey()
    {
        auto it= mp.begin();
        int times = it->second.second;
        int key = it->first;
        while(it != mp.end()){
            if(it->second.second < times){
                times = it->second.second;
                key = it->first;
            }
            it++;
        }
        return key;
    }
private:    
    unordered_map<int,pair<int,int>>mp;
    int N= 0;
    int cur_time = 0; // 记录当前的时间
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 

int main()
{
    LRUCache* obj = new LRUCache(2);
    
    cout << "get "<<  obj->get(2) << endl;
    obj->put(2,6);

    cout << "get "<<  obj->get(1) << endl;
    obj->put(1,5);

    obj->put(1,2);
    cout << "get "<<  obj->get(1) << endl;
    cout << "get "<<  obj->get(2) << endl;
    

    free(obj);
    cout << "hell22o" << endl;
    return 0;
}