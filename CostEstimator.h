#ifndef COSTESTIMATOR_H
#define COSTESTIMATOR_H

#include "item.h"
#include <vector>

/**
 * The CostEstimator class represents a cost estimator that calculates estimates for items.
 * This class provides functionality to add, remove, and clear items, as well as save and load items.
 * It also allows for displaying the estimates of the items.
 */
class CostEstimator {
public:
    /**
     * Adds an item to the cost estimator.
     * @param item The item to be added.
     */
    void addItem(const Item& item);

    /**
     * Removes an item from the cost estimator.
     * @param itemName The name of the item to be removed.
     */
    void removeItem(const std::string& itemName);

    //Clears all the items from the cost estimator.    
    void clearItems();

    /**
     * @brief Saves the items in the cost estimator to a file.
     * 
     * The saved items can be loaded later using the loadItems() function.
     */
    void saveItems() const;

    //Displays the estimates of the items in the cost estimator.    
    void showEstimates() const;

    /**
     * Loads the items from a file into the cost estimator.
     * The loaded items replace the existing items in the cost estimator.
     */
    void loadItems();

private:
    std::vector<Item> items; /**< The vector of items in the cost estimator. */
};

#endif // COSTESTIMATOR_H