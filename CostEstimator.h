#ifndef COST_ESTIMATOR_H
#define COST_ESTIMATOR_H

#include "Item.h"
#include <vector>
#include <iostream>

class CostEstimator {
private:
    std::vector<Item> items;

public:
    void addItem(const Item& item);
    void removeItem(const std::string& itemName);
    void clearItems();
    void saveItems() const;
    void loadItems();
    void showEstimates() const;
};

#endif // COST_ESTIMATOR_H
