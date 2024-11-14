#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        string title_temp = " "+ title + " ";
        int  i = 0;; 
        int j = i + 1;
        while( j< title_temp.size() ){
            if( title_temp[j] == ' '){
                int len = j -i - 1;
                if(len > 2){

                    if(title_temp[i+1] >= 'a' && title_temp[i+1]<= 'z'){
                        title_temp[i+1] = title_temp[i+1] + ('A' - 'a');
                    }
                    for(int k = i+ 2; k < j; k++){
                        if(title_temp[k] >= 'A' && title_temp[k]<= 'Z'){
                            title_temp[k] += ('a' - 'A');
                        }
                   }
                } else {
                   for(int k = i+ 1; k < j; k++){
                        if(title_temp[k] >= 'A' && title_temp[k]<= 'Z'){
                            title_temp[k] += ('a' - 'A');
                        }
                   }
                }
                i = j;
                
            }
            j++;
        }
        title_temp.pop_back();
        title_temp = title_temp.substr(1);
        cout<< title_temp << endl;
        return title_temp;
        
    }
};

int main()
{
    Solution s1;
    string title = "capiTalIze tHe titLe";
    // string title = "First leTTeR of EACH Word";
    // string title = "i lOve leetcode";
    s1.capitalizeTitle(title);
    printf("%d %d \n", 'a', 'A');

    cout << "hell22o" << endl;
    return 0;
}