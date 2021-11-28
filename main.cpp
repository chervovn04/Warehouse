#include <iostream>
#include "Generator.h"

int main() {
    int k, n, m;
    std::cin >> k >> m;
    std::vector<ItemType*> types;
    std::vector<IAsker*> shops;
    std::string name;
    int capacity, days, days_critical, weight, packs, price, spoiled_price, price_factory;
    for (int i = 0; i < k; ++i) {
        std::cin >> name >> capacity >> days >> days_critical >> weight >> packs >> price >> spoiled_price >> price_factory;
        types.emplace_back(new ItemType(name, capacity, days, days_critical, weight, packs, price, spoiled_price, price_factory));
    }

    shops.reserve(m);
    for (int i = 0; i < m; ++i) {
        shops.emplace_back(new Shop());
    }

    auto* warehouse = new Warehouse();
    auto* factory = new Factory();
    auto* generator = new Generator(warehouse, factory, shops, types);

    int cnt_days = 365;
    for (int day = 1; day < cnt_days; ++day){
        /*if (day == 99)
            int t = 0;*/
        generator->process();
        //std::cout << "============================== Day " << day << " ==============================\n";
        if (day == cnt_days - 1)
            generator->log();
    }

}
/*
3 5
Kolbasa 100 7 2 10 5 2500 2400 2000
Potato 5000 10 1 5 1 250 220 180
Moloko-Milk-for-englishman 1000 14 3 1 20 1340 950 700
*/
