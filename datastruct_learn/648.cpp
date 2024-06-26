#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(int i = 0 ; i< dictionary.size(); i++){
            Myset.insert(dictionary[i]);
        }
        string resu = "";
        int i = 0; 
        int j = 0;
        while(i<=j && j < sentence.length()){
            if(j ==  sentence.length()- 1){
                cout << sentence.substr(i, (j -i + 1)) << endl;
                resu = resu + " " + findDir(sentence.substr(i, (j -i + 1)));
            }
            if(sentence[j] != ' '){
                j++;
                continue;
            }
            cout << sentence.substr(i, (j-1 -i + 1)) << endl;
            resu = resu + " " + findDir(sentence.substr(i, (j-1 -i + 1)));
            i = j+1;
            j = i;
        }

        cout << resu << endl;
        return resu.substr(1, resu.length()-1);
    }
    string findDir(string str)
    {
        auto it = Myset.begin();
        while(it != Myset.end()){
            if(str.find(*it) == 0){
                return *it;
                break;
            }
            it++;
        }
        return str;
    }
private:
    set<string>Myset;
};
 

int main()
{
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    Solution S1;
    string resu=  S1.replaceWords(dictionary, sentence);
    cout << "main=" << resu << endl;

    
    return 0;
}