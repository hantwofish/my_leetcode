#include"../INCLUDE/STLCOMMON.h"
#include"../INCLUDE/COMMONALO.h"
#include <iostream>
// #include "../INCLUDE/TREE.h"

using namespace std;

#define IN 1
#define OUT 0

class Solution{

public:
    void updat_today_price(double peice)
    {
        today_price = peice;
    }
    void in_or_out_record(double num, double price, bool is_in)
    {
        today_price = price;
        in_out_map[is_in].push_back({price, num});
        
        double mai_ru_cheng_ben = 0; // 买入成本
        double chi_cang_fen_shu = 0; // 持仓份数
        
        double profile_rate = 0; // 利润率
        double li_run = 0;
        double mai_chu_dedao = 0;


        for(int i = 0; i< in_out_map[IN].size(); i++){
            chi_cang_fen_shu += (in_out_map[IN][i].second * in_out_map[IN][i].first * (1- buyrate)) / in_out_map[IN][i].first;
            // cout << in_out_map[IN][i].first << " " <<  in_out_map[IN][i].second << endl;
            mai_ru_cheng_ben += (in_out_map[IN][i].first * in_out_map[IN][i].second); 
        }

        for(int i = 0; i< in_out_map[OUT].size(); i++){
            chi_cang_fen_shu -= in_out_map[OUT][i].second;
            mai_chu_dedao += ((in_out_map[OUT][i].first * in_out_map[OUT][i].second)) * (1- outrate); 
        }

        cout << "_______________________" << endl;
        cout << "持仓份数=" << chi_cang_fen_shu << " 当前价格=" << today_price << " 卖出得到=" << mai_chu_dedao << " 当前估值= " << chi_cang_fen_shu * today_price << endl;
        cout << "买入成本=" << mai_ru_cheng_ben << " 利润=" << chi_cang_fen_shu * today_price + mai_chu_dedao - mai_ru_cheng_ben << endl;
        

    
        
        
        // double cost_val = chi_cang_fen_shu * today_price;
        
        // cout << chi_cang_fen_shu << " * " << (mai_ru_cheng_ben / chi_cang_fen_shu) << " = " << mai_ru_cheng_ben << endl;
        // cout << cost_val - mai_ru_cheng_ben << " rate= " << (cost_val - mai_ru_cheng_ben) / mai_ru_cheng_ben * 100 << "%" << endl;

    }

private:
    // const double buyrate = 0.001; // 0.1%
    // const double outrate = 0.005; // 0.5%

    const double buyrate = 0; // 0.%
    const double outrate = 0; // 0%
    unordered_map<bool, vector< pair<double,double>> > in_out_map;
    double today_price = 0; // 今日股价


};
// i= 99
// _______________________
// 持仓份数=500 当前价格=7.8 卖出得到=390000 当前估值= 3900
// 买入成本=384305 利润=9595
// _______________________
// 持仓份数=1000 当前价格=7.61 卖出得到=390000 当前估值= 7610
// 买入成本=388110 利润=9500

int main()
{
    // Solution tian_hong_shi_pin; // 天弘食品 001632
    // tian_hong_shi_pin.updat_today_price(2.1085);
    // tian_hong_shi_pin.in_or_out_record(807, 2.2017, IN);
    // tian_hong_shi_pin.in_or_out_record(1, 2.1085, IN);

    // tian_hong_shi_pin.in_or_out_record(200, 2.2085, OUT);
    // tian_hong_shi_pin.in_or_out_record(200, 2.1085, IN);

    // tian_hong_shi_pin.in_or_out_record(200, 2.2085, OUT);
    // tian_hong_shi_pin.in_or_out_record(200, 2.1085, IN);

    // tian_hong_shi_pin.in_or_out_record(200, 2.2085, OUT);
    // tian_hong_shi_pin.in_or_out_record(200, 2.1085, IN);

    // tian_hong_shi_pin.in_or_out_record(200, 2.2085, OUT);
    // tian_hong_shi_pin.in_or_out_record(200, 2.1085, IN);

    // tian_hong_shi_pin.in_or_out_record(200, 2.2085, OUT);
    // tian_hong_shi_pin.in_or_out_record(200, 2.1085, IN);  

    Solution gong_shang_yin_hang; // 601398 工商银行

    gong_shang_yin_hang.in_or_out_record(1000, 7.61, IN);

    for(int i= 0; i < 100;i++){
        cout << "i= " << i << endl;
        gong_shang_yin_hang.in_or_out_record(500, 7.81, OUT);
        gong_shang_yin_hang.in_or_out_record(500, 7.61, IN);
    }
    gong_shang_yin_hang.in_or_out_record(1000, 7.81, OUT);


    


    cout << "[info] main end ..." << endl << endl;

    return 0;
}


// g++ 2766.cpp -std=c++11 -o main.exe  && ./main.exe

// rm -f test.exe
// # clear &&  g++ --std=c++11 test.cpp -o main && ./main

// #rm -f test.exe ; cls;  g++ --std=c++11 test.cpp -o main.exe ; .\main.exe

// 鎷疯礉鏂囦欢锛�./file_run.sh 00_00.cpp
// 杩愯鏂囦欢  ./file_copy.sh  00_00.cpp