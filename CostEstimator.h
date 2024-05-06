#ifndef COSTESTIMATOR_H
#define COSTESTIMATOR_H

#include "item.h"
#include <vector>

class CostEstimator {
public:
    void addItem(const Item& item);
    void removeItem(const std::string& itemName);
    void clearItems();
    void saveItems() const;
    void showEstimates() const;
    void loadItems();

private:
    std::vector<Item> items;
};

#endif // COSTESTIMATOR_H