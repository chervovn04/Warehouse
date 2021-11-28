#include "Generator.h"

#include <utility>

Generator::Generator(IUnit* warehouse, IGiver* factory, std::vector<IAsker*> shops, std::vector<ItemType*> items)
: warehouse_(warehouse)
, factory_(factory)
, shops_(std::move(shops))
, items_(std::move(items)) {}

void Generator::process() {
    warehouse_->process();
    factory_->process();
    for (auto & shop : shops_) {
        dynamic_cast<IGiver*>(warehouse_)->give(shop);
    }
    for (auto & shop : shops_) {
        shop->ask(dynamic_cast<IGiver*>(warehouse_), items_);
    }
    dynamic_cast<IGiver*>(factory_)->give(dynamic_cast<IAsker*>(warehouse_));
    dynamic_cast<IAsker*>(warehouse_)->ask(factory_, items_);
}


void Generator::log() {
    int get = 0;
    int money = 0;
    int cnt_spoiled_sold = 0;
    for (auto & shop : shops_) {
       money += dynamic_cast<Shop*>(shop)->get_money();
       cnt_spoiled_sold += dynamic_cast<Shop*>(shop)->get_count_spoiled();
    }
    std::cout << "Clear money: " << money << std::endl;
    money -= dynamic_cast<Factory*>(factory_)->get_money();

    std::cout << "Money balance: " << money << std::endl;

    int lose_money = dynamic_cast<Warehouse*>(warehouse_)->get_lose_money();
    int erase_items = dynamic_cast<Warehouse*>(warehouse_)->get_erase_items();

    std::cout << "Lost money: " << lose_money << std::endl;
    std::cout << "Trashed: " << erase_items << std::endl;
    std::cout << "Spoiled sold: " << cnt_spoiled_sold << std::endl;
    std::cout << "\nStorage: " << std::endl;
    for (auto & type: dynamic_cast<Warehouse*>(warehouse_)->get_storage()) {
        std::cout << type.first.get_name() << std::endl;
        int cnt = 0;
        int cnt_spoiled = 0;
        for (auto & item : type.second) {
            if (item.is_spoiled()) {
                ++cnt_spoiled;
            } else {
                ++cnt;
            }
        }
        std::cout << "\tCount of not spoiled: " << cnt << std::endl;
        std::cout << "\tCount of spoiled: " << cnt_spoiled << std::endl;
    }
    std::cout << "\nFactory queue: " << std::endl;
    for (auto & line : dynamic_cast<Factory*>(factory_)->get_wait_list()) {
        std::cout << line.item.get_name() << "\tx" << line.count << "\twill arrive in " << line.time << " day(s)" << std::endl;
    }
}