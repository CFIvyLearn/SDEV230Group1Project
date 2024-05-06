#ifndef ITEM_H
#define ITEM_H

#include <string>

/**
 * Represents an item with a name, quantity, and unit price.
 */
class Item {
public:
    /**
     * Default constructor.
     * Initializes the item with an empty name, quantity of 0, and unit price of 0.0.
     */
    Item() : name(""), quantity(0), unit_price(0.0) {}

    /**
     * Constructor with parameters.
     * Initializes the item with the given name, quantity, and unit price.
     * @param name The name of the item.
     * @param quantity The quantity of the item.
     * @param unit_price The unit price of the item.
     */
    Item(const std::string& name, int quantity, double unit_price)
        : name(name), quantity(quantity), unit_price(unit_price) {}

    /**
     * Get the name of the item.
     * @return The name of the item.
     */
    const std::string& getName() const {
        return name;
    }

    /**
     * Get the quantity of the item.
     * @return The quantity of the item.
     */
    int getQuantity() const {
        return quantity;
    }

    /**
     * Get the unit price of the item.
     * @return The unit price of the item.
     */
    double getUnitPrice() const {
        return unit_price;
    }

private:
    std::string name;     // The name of the item
    int quantity;         // The quantity of the item
    double unit_price;    // The unit price of the item
};

#endif // ITEM_H