#ifndef WAREHOUSE2_GENERATOR_H
#define WAREHOUSE2_GENERATOR_H

#pragma once

#include "Delivery.h"
#include "Shop.h"
#include "Factory.h"
#include "Warehouse.h"

class Generator : public IUnit {
public:
    Generator(IUnit*, IGiver*, std::vector<IAsker*>, std::vector<ItemType*>);
    void process();
    void log();

private:
    IUnit *warehouse_;
    IGiver *factory_;
    std::vector<IAsker*> shops_;
    std::vector<ItemType*> items_;
};


#endif //WAREHOUSE2_GENERATOR_H
