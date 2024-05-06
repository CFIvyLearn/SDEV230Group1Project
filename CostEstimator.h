#ifndef COSTESTIMATOR_H
#define COSTESTIMATOR_H

#include "item.h"

class CostEstimator {
public:
    CostEstimator() : itemCount(0) {} // Initialize itemCount to 0 in the constructor

    // Add an item to the cost estimator
    void addItem(const Item& item);

    // Remove an item from the cost estimator by its name
    void removeItem(const std::string& itemName);

    // Clear all items from the cost estimator
    void clearItems();

    // Save the items to a file
    void saveItems() const;

    // Show the estimates for each item
    void showEstimates() const;

    // Load items from a file
    void loadItems();

private:
    static const int MAX_ITEMS = 100; // Maximum number of items
    Item items[MAX_ITEMS]; // Array of items
    double totalCosts[MAX_ITEMS]; // Array of total costs
    int itemCount; // Current number of items
};

#endif // COSTESTIMATOR_H