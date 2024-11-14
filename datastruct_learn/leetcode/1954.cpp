#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long allvalue = 0;
        long long i = 1;
        for( i= 1;i < INT64_MAX; i++){
            // cout << "i= "<< i << endl;
            allvalue = allvalue + calAllApplebyindex(i);
            // cout << "i= "<< i << " allvalue= "  << allvalue << endl;
            if(allvalue >= neededApples){
                // cout << "i= " << i << " length= " << i *8 << endl;
                return i* 8;
            }
        }
        return 0;


    }
private:
    long long calAllApplebyindex(long long yindex)
    {
        long long temp = abs(yindex);
        long long allval = 0;
        // long long allvaltemp = 0;
        // for(long  long i = 0; i <= yindex; i++){
        //     allvaltemp += abs(i) + abs(yindex);
        // }
        allval = yindex * (yindex + 1) / 2 + yindex * (yindex + 1);
        // cout << "allvla= " << allval << " temp= " << allvaltemp << endl;
        allval = 8 * allval;
        allval = allval - 4 * abs(yindex) - 4 * (abs(yindex) + abs(yindex));

        return allval;
    }
};

int main()
{
    Solution s1;
    // s1.calMaxArray();
    long long need = 500;
    s1.minimumPerimeter(need);

    

    cout << "hell22222o" << endl;
    return 0;
}