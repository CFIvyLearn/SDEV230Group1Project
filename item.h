#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(const std::string& name, int quantity, double unit_price)
        : name(name), quantity(quantity), unit_price(unit_price) {}

    const std::string& getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    double getUnitPrice() const {
        return unit_price;
    }

private:
    std::string name;
    int quantity;
    double unit_price;
};

#endif // ITEM_H