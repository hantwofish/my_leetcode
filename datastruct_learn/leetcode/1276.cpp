class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices == 0 && cheeseSlices ==0 )return {0,0};
        if(tomatoSlices == 0 || cheeseSlices ==0 )return {};
        if(tomatoSlices %2 != 0) return {};
        int a = tomatoSlices/2-cheeseSlices;
        int b = 2*cheeseSlices - tomatoSlices/2;
        if(a<0 || b <0){
            return {};
        }

        return {a,b};

    }
};