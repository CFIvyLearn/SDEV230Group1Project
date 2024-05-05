#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    std::string name;
    int quantity;
    double unit_price;

    Item(std::string n, int q, double p) : name(n), quantity(q), unit_price(p) {}

    double getTotalCost() const {
        return quantity * unit_price;
    }
};

#endif // ITEM_H
