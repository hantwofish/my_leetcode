#include"../STLCOMMON.h"

using namespace std;

void test_pair()
{
    auto i = make_pair(3,"2");
    pair<int, string>temp;
    temp = make_pair(3,"2");
    cout << "first= " << temp.first << " second= " << temp.second << endl;
    temp = {4, "sss"};
    cout << "first= " << temp.first << " second= " << temp.second << endl;



    // unordered_map<int,pair<int,string>> unor_map;
    // unor_map.insert( {1, make_pair(3,"-")}  );
    // unor_map.insert(  pair<int,pair<int,string>>(3,i)      );
    // unor_map.insert(  pair<int,pair<int,string>>(0,   pair<int,string>(2,"2")   )   );

    // unor_map.erase(2);

    // for(auto it = unor_map.begin(); it != unor_map.end(); it++){
    //     cout << "first= " << it->first << endl;
    // }

}
void test_tuple()
{
    tuple<int, int, string> temp;
    temp = make_tuple(9, 0, "Ss");
    cout<< "first= " << get<0>(temp) << " seconde= " << get<1>(temp)<< " third= " << get<2>(temp) << endl;
}

int main()
{
    test_pair();
    test_tuple();
    return 0;
}


// https://blog.csdn.net/sevenjoin/article/details/81937695