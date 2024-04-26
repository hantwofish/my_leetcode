#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class SnapshotArray {
public:
    SnapshotArray(int length) {
        data.resize(length,0);
    }
    
    void set(int index, int val) {
        data[index] = val;
    }
    
    int snap() {
        snapIdVec[setAllTimes] = data;
        setAllTimes++;
        return setAllTimes -1;
    }
    
    int get(int index, int snap_id) {
        return snapIdVec[snap_id][index];
    }
private:
    int setAllTimes = 0;
    vector<int>data;
    unordered_map<int, vector<int>> snapIdVec;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */ 

int main()
{
    SnapshotArray* obj = new SnapshotArray(3);
    obj->set(0,5);
    int param_2 = obj->snap();
    int param_3 = obj->get(0,0);
    
    cout << "hell22o" << endl;
    return 0;
}