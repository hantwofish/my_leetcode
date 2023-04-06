#include"../../STLCOMMON.h"
using namespace std;

class Node{
public:
    Node(int x, int y): m_x(x), m_y(y) {}
public:
    int m_x;
    int m_y;

};
bool Mycompare(Node& n1, Node &n2)
{
    return n1.m_x > n2.m_x;
}
void Print(vector<Node> &vec)
{
    for(int i = 0; i< vec.size(); i++){
        auto it = vec[i];
        cout << it.m_x << " " << it.m_y << endl;
    }
}

struct cmp{
    bool operator()(const Node&n1, const Node &n2)
    {
        return n1.m_x > n2.m_x;
    }
};

int main()
{
    Node n1(3,5);
    Node n2(4,5);
    Node n3(6,5);
    vector<Node> vec;
    vec.push_back(n1);
    vec.push_back(n2);
    vec.push_back(n3);
    vec.erase(vec.begin()+ 1);
    Print(vec);

    vec.pop_back();
    Print(vec);



    sort(vec.begin(),vec.end(),Mycompare );
    Print(vec);

}