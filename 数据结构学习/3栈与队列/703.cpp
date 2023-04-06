#include"../../STLCOMMON.h"
using namespace std;

bool Cmp(int a, int b)
{
    return a> b;
}

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        K= k;
        for(auto i : nums){
            data.insert(i);
        }
        // Print(data);
    
    }
    
    int add(int val) 
    {
        data.insert(val);
        // Print(data);
        int times = 1;
        int resu = 0;
        int N= data.size();
        for(auto it = data.begin(); it != data.end();it++,times++){
            if( times == N-K+1){
                resu = *it;
                break;
            }
        }
        // cout << "resu= "  << resu << endl;
        return resu;

    }
    void Print(multiset<int>&data)
    {
        for(auto it = data.begin(); it != data.end();it++){
            cout << *it << " " ;
        }   
        cout << endl;
    }
public:
    multiset<int>data;
    int K = 0;
};

int main()
{
    int k =3;
    vector<int>nums= {4,5,8,2};
    // nums.clear();
    KthLargest p(k,nums);

    p.add(3);
    p.add(5);
    p.add(10);
    p.add(9);
    p.add(4);
    

}