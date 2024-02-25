#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        mySet.clear();
    }
    
    bool insert(int val) {
        if(mySet.find(val) != mySet.end()){ //  存在
            return false;
        }
        mySet.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(mySet.find(val) == mySet.end()){ // 不存在
            return false;
        }
        mySet.erase(val);
        return true;
    }
    
    int getRandom() {
        int size = mySet.size();
        int diff = rand() % size;
        auto it = mySet.begin();
        while(diff >0){
            it++;
            diff--;
        }
        return *it;
    }
private:    
    set<int>mySet;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    Solution s1;
    // s1.calMaxArray();

    

    cout << "hell22o" << endl;
    return 0;
}