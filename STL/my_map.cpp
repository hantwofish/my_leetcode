#include"../STLCOMMON.h"

using namespace std;
#define N 10

unordered_map<int, pair<int,int>>g_MyundoMap;
map<int, pair<int,int>>g_MyMap;


bool cmp(unordered_map<int, pair<int,int>>&map1,unordered_map<int, pair<int,int>>&map2)
{    
    return true;
}

void PrintUnMap(unordered_map<int, pair<int,int>>&yundoMap)
{
    cout << "--------unorderMap---start------------"<< endl;
    auto it = yundoMap.begin();
    while (it != yundoMap.end()){
        cout << it->first << " {" << (it->second).first  << " " << (it->second).second << "}"<< endl;
        it++;
    }  
    cout << "-----------end------------" << endl; 

}
void PrintMap(map<int, pair<int,int>>&yundoMap)
{
    cout << "-------Map----start------------"<< endl;
    auto it = yundoMap.begin();
    while (it != yundoMap.end()){
        cout << it->first << " {" << (it->second).first  << " " << (it->second).second << "}"<< endl;
        it++;
    }  
    cout << "-----------end------------" << endl;

}
void init()
{
    for(int i = 0; i < N ; i++){
        g_MyundoMap.insert( { rand()%3,  {rand()% N, i}});
        g_MyMap.insert( { rand()%3,  {rand()% N, i}});
    }
    PrintUnMap(g_MyundoMap);
    // PrintMap(g_MyMap);
    // sort(g_MyundoMap.begin(),g_MyundoMap.end());
    PrintMap(g_MyMap);
}




int main()
{
    init();
    return 0;

}


