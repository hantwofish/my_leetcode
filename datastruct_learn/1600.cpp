#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        root = kingName;
        isLive[root] = true;
    }
    
    void birth(string parentName, string childName) {
        u_map[parentName].push_back(childName);
        isLive[childName] = true;
    }
    
    void death(string name) {
        isLive[name] = false;
    }
    
    vector<string> getInheritanceOrder() {
        order.clear();
        FrontSearch(root);
        
        vector<string>resu;
        for(auto i : order){
            if(isLive[i] == false) continue;
            
            resu.push_back(i);
        }
        Print(resu);
        return resu;
    }
    void FrontSearch(string cur)
    {
        if(cur == "") return;
        order.push_back(cur);
        for(int i = 0; i < u_map[cur].size();i++){
            FrontSearch(u_map[cur][i]);
        }

    }
private:
    void Print(vector<string>&order)
    {
        for(auto i : order){
            cout << i << " ";
        }
        cout << endl;

    }
private:
    unordered_map<string, vector<string>>u_map;
    unordered_map<string, bool> isLive;
    vector<string>order;
    string root;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

int main()
{
    ThroneInheritance s1("king");
    s1.birth("king", "alice");
    s1.birth("king", "bob");
    s1.birth("alice", "jack");
    s1.getInheritanceOrder();
    

    cout << "hell22o" << endl;
    return 0;
}