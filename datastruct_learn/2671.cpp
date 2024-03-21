#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class FrequencyTracker {
public:
    FrequencyTracker() {

    }
    /*
        添加前，原先有无这个数：
            无：加进去，更新 key_f_map  f_type_map
            有：找到旧频率，新频率，旧频率减一，新频率加一
    
    */

    void add(int number) {
        cout <<"add " << number  << " " <<key_f_map[number] << endl;
        if(key_f_map.find(number) == key_f_map.end()|| key_f_map[number] < 0){
            key_f_map[number] = 1;
            int frequ_new = key_f_map[number];
            f_type_map[frequ_new]++;
        }else{
            int fre_que_old = key_f_map[number];
            key_f_map[number]++;
            int frequ_new = key_f_map[number];

            f_type_map[fre_que_old]--;
            f_type_map[frequ_new]++;
        }    
    }
    
    void deleteOne(int number) {
        cout <<"deleteOne " << number << endl;
        if(key_f_map.find(number) == key_f_map.end()){
            return;
        }

        int fre_que_old = key_f_map[number];
        key_f_map[number]--;
        int frequ_new = key_f_map[number];

        f_type_map[fre_que_old]--;
        f_type_map[frequ_new]++;
    }
    
    bool hasFrequency(int frequency) {
        cout << "hasFrequency " << frequency << "= " <<f_type_map[frequency]  << endl;
        return f_type_map[frequency]>0;
    }
private:    
    unordered_map<int, int>key_f_map;
    unordered_map<int,int>f_type_map;
};   

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */

int main()
{
    Solution s1;
    // s1.calMaxArray();
    
    

    cout << "hell22o" << endl;
    return 0;
}