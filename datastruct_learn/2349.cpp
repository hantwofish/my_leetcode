#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class NumberContainers {
public:
    NumberContainers() {

    }
    
    void change(int index, int number) {
        if(myMap.find(index) == myMap.end()){
            myMap[index] = number;
            numberMap[number].insert(index);
            return;
        }
        int oldNum = myMap[index];
        

        // 移除 old index
        numberMap[oldNum].erase(index);

        myMap[index] = number;
        numberMap[number].insert(index);
    }
    
    int find(int number) {
        if(numberMap[number].empty()) return -1;
        return *(numberMap[number].begin());
    }
private:
    map<int,int> myMap; // index -> numbeer
    unordered_map<int, set<int>> numberMap;
};
 

int main()
{
    long long num = 0;
    long long minNum =  -1 * ( (long long)1 << 32);
    long long maxNum = (long long)1 << 32;
    cout << minNum << endl;
    cout << maxNum << endl;
    
    cout << "hell22o" << endl;
    return 0;
}