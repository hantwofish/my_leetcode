#include"../STLCOMMON.h"
#include"../COMMONALO.h"


using namespace std;

class Solution {
public:
    int magicTower(vector<int>& nums) { // 贪心算法加优先队列
        long long cur_sum = 0;
        int times = 0;
        vector<int>modeEleArray;
        for(int i=0; i< nums.size(); i++){
            if(nums[i]< 0){
                minQue.push(nums[i]);
            }
            cur_sum = cur_sum + nums[i];
            if(cur_sum < 0){
                times++; // 将最小的移动到末尾
                cout << "minQue top= " << minQue.top() << endl;
                cur_sum = cur_sum - minQue.top();
                modeEleArray.push_back(minQue.top());
                minQue.pop();
            }
        }
        int needDeleteTimes = times;

        cout << "cursum= " << cur_sum << " needDeleteTimes " << needDeleteTimes << " que.size()=" << minQue.size() << endl;
        // 将堆中元素加入到生命值中

        cout << "cursum= " << cur_sum << " times= " << times << endl;
        for(int i=0; i<modeEleArray.size();i++ ){
           cur_sum +=  modeEleArray[i];
        }
        return (cur_sum >= 0 ? times : -1);
    }
    int sumFunc(vector<int>&nums)
    {
        int sumtemp =0;
        for(int i= 0; i< nums.size(); i++){
            sumtemp += nums[i];
        }
        cout << sumtemp << endl;
        return 0;
    }
private:
    priority_queue<int,vector<int>, greater<int>> minQue; // 小顶堆
};



int main()
{
    Solution s1;
    // s1.calMaxArray();
    vector<int>nums = {-9635,71923,-37495,8366,54303,-86422,-48303,-47858,98424};
    int resu = s1.magicTower(nums);
    cout << "resu= " << resu << endl;
    s1.sumFunc(nums);

    

    cout << "hell22o222" << endl;
    return 0;
}