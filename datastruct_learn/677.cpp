#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class MapSum {
public:
    MapSum() {

    }
    
    void insert(string key, int val) {
        u_map[key] = val;
    }
    
    int sum(string prefix) {
        int resu = 0;
        auto it =  u_map.begin();
        while(it != u_map.end()){
            // if(it->first.find(prefix) != string::npos){
            if(it->first.find(prefix) == 0){ // 以 prefix 开头
                resu +=( it->second);
            }
            it++;
        }
        return resu;
    }
private:
    unordered_map<string, int>u_map;
};
 

int main()
{
    
    cout << "hell22o" << endl;
    return 0;
}