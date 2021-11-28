#ifndef WAREHOUSE2_WAREHOUSE_H
#define WAREHOUSE2_WAREHOUSE_H

#pragma once

#include "Delivery.h"

class Warehouse : public IAsker, public IGiver {
public:
    Warehouse();
    void process();
    void ask(IGiver*, std::vector<ItemType*>);
    void add(Item);
    void give(IAsker*);
    void push(Delivery*);

    bool is_spoiled(ItemType type);

    int get_lose_money();
    int get_erase_items();
    std::map<ItemType, std::vector<Item>>& get_storage();

private:
    std::map<IAsker*, std::map<ItemType, std::vector<Item>>> count_give_;
    std::map<ItemType, std::map<IAsker*, int>> count_ask_;
    std::map<ItemType, std::vector<Item>> storage_;
    std::map<ItemType, double> B_score_, count_;
    int lose_money_ = 0;
    int erase_items_ = 0;
};


#endif //WAREHOUSE2_WAREHOUSE_H
