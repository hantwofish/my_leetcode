#include"../STLCOMMON.h"
using namespace std;

class Union{
public:
    void init()
    {
        fa.resize(N,0);
        for(int i = 0; i < fa.size(); i++){
            fa[i] = i;
        }
    }
    // 找到当前节点的父节点
    int find(int a)
    {
        if(fa[a] == a){
            return a;
        }else{
            return find(fa[a]);
        }

    }
    // 将两个节点合并
    int merge(int a, int b)
    {
        int aa = find(a);
        int bb = find(b);
        if(aa == bb){
            return 0;
        }
        // 将a 合并到b
        fa[aa] = bb;
        return 1;
    }
    void PrinVec(vector<int>&fa)
    {
        for(int i = 0 ; i< fa.size(); i++){
            printf("%3d", i);
        }
        printf("\n");

        for(int i = 0 ; i< fa.size(); i++){
            printf("---");
        }
        printf("\n");

        for(int i = 0 ; i< fa.size(); i++){
            printf("%3d", fa[i]);
        }
        printf("\n");
    }
public:
    int N;
    vector<int>fa;

};


int main()
{
    Union u1;
    u1.N = 6;
    u1.init();
    u1.PrinVec(u1.fa);

    int a,b ;
    while (cin>> a >> b){  
        printf("merge %d with %d : %d\n", a, b, u1.merge(a, b));
        u1.PrinVec(u1.fa);
    }
    
    

    return 0;
}