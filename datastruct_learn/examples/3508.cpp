

#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
#include "../INCLUDE/TREE.h"



using namespace std;


class Router {
public:
    Router(int memoryLimit) {
        N = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        auto add_value = make_tuple(source,destination ,timestamp );
        // cout << "add start " << source << " " << destination << " " << timestamp << endl;
        
        // string val = cal_string(source,destination, timestamp);
        bool  is_duple = false;
        for(int i = 0; i < vec_bak.size(); i++){
            if(vec_bak[i] ==  add_value){
                is_duple = true;
            }
        }

        if(is_duple){
            return false;
        }

        tuple<int,int,int>val_back;

        if(que_vec.size() >= N){
            val_back =  que_vec.front();
            que_vec.pop();

            auto ifind = find(vec_bak.begin(),vec_bak.end(), val_back);

            vec_bak.erase(ifind);
            // for(auto i  = vec_bak.begin(); i != vec_bak.end(); i++){
            //     if( (*i) == val_back){
            //         vec_bak.erase(i);
            //         break;
            //     }
            // }
            // cout << "add erase " << get<0>(val_back) << " " << get<1>(val_back) << " " << get<2>(val_back) << endl;
        }

        // vector<int>temp;
        // temp.push_back(get<0>(val_back));
        // temp.push_back(get<1>(val_back));
        // temp.push_back(get<2>(val_back));

        // string cal_val = cal_string(temp[0], temp[1], temp[2]);

        // que_vec.pop();

        
        
        
        que_vec.push(add_value);
        vec_bak.push_back(add_value);
        // cout << "add ok" << source << " " << destination << " " << timestamp << endl;
        return true;
    }
    
    vector<int> forwardPacket() {
        if(que_vec.empty()){
            return {};
        }


        auto val = que_vec.front();
        vector<int>temp;
        temp.push_back(get<0>(val));
        temp.push_back(get<1>(val));
        temp.push_back(get<2>(val));

        // string cal_val = cal_string(temp[0], temp[1], temp[2]);

        que_vec.pop();
        auto ifind = find(vec_bak.begin(),vec_bak.end(), val);

        vec_bak.erase(ifind);
        // for(auto i  = vec_bak.begin(); i != vec_bak.end(); i++){
        //     if( (*i) == val){
        //         vec_bak.erase(i);
        //         break;
        //     }
        // }
        return temp;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int times= 0;
        for(int i = 0; i< vec_bak.size(); i++){
            vector<int>temp;
            temp.push_back(get<0>(vec_bak[i]) );
            temp.push_back(get<1>(vec_bak[i]) );
            temp.push_back(get<2>(vec_bak[i]) );
            if(temp[1] == destination && temp[2] >= startTime && temp[2]<= endTime){
                times++;
            }

        }
        return times;
    }

private:
    string cal_string(int source, int destination, int timestamp) 
    {
        string val = to_string(source) +","+ to_string(destination)+","+ to_string(timestamp);
        return val;
    }
private:
    queue<tuple<int,int,int>> que_vec;
    vector<tuple<int,int,int>>vec_bak;
    int N = 0;
};


/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

int main()
{
    Router router(3); // 初始化路由器，内存限制为 3。
    router.addPacket(1, 4, 90); // 数据包被添加，返回 True。
    router.addPacket(2, 5, 90); // 数据包被添加，返回 True。
    router.addPacket(1, 4, 90); // 这是一个重复数据包，返回 False。
    router.addPacket(3, 5, 95); // 数据包被添加，返回 True。
    router.addPacket(4, 5, 105); // 数据包被添加，[1, 4, 90] 被移除，因为数据包数量超过限制，返回 True。
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe