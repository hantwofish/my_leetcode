#include"../STLCOMMON.h"

using namespace std;

// map key 不能为 vector

struct CmpByValueMax {
    bool operator()(const pair<int, int>&k1, const pair<int, int>&k2) const
    {
        if(k1.second > k2.second){ //降序排列
            return true;
        }else if (k1.second == k2.second) {
            return k1.first < k2.first;
        }
        return false;
    }
};
class SortMap{
public:
    void init()
    {
        myMap.insert({{1,2},9});
        myMap.insert({{1,3},4});
        myMap.insert({{3,2},4});
        myMap.insert({{3,1},8});
        myMap.insert({{4,4},0});
        myMap.insert({{3,4},0});
        Print(myMap);
    }
    void Print(map<pair<int,int>,int, CmpByValueMax>&myMap)
    {
        cout << "--------- start---------" << endl;
        auto it= myMap.begin();
        while(it != myMap.end()){
            pair<int,int>itKey = it->first;
            int val = it->second;
            cout << "{ " << itKey.first << " , " << itKey.second << " } -> " << val << endl;
            it++;
        }
        cout << "--------- end---------" << endl;
    }
    void testOrderMap()
    {
        Print(myMap);
        pair<int,int> deleNum = {3,2};
        if(myMap.find(deleNum) != myMap.end()){
            cout << "Found" << endl;
        }else {
            cout << "Not Found" << endl;
        }
        myMap.erase(deleNum);
        Print(myMap);

        

    }


public:
    map<pair<int,int>,int, CmpByValueMax>myMap; //map 自动排序
};



int main()
{
    // map<int, int> mp;
    // mp.insert({1,3});
    // mp.insert({2,5});
    // cout << mp.begin()->first << endl;
    // mp.erase(1);
    // mp.insert({3,3});
    // cout << mp.begin()->first << endl;
    SortMap s1;
    s1.init();
    s1.testOrderMap();
    return 0;

}


