#include "CostEstimator.h"
#include <fstream>
#include <algorithm>
#include <iostream>

void CostEstimator::addItem(const Item& item) {
    if (itemCount < MAX_ITEMS) {
        items[itemCount] = item; // Add the item to the items array
        totalCosts[itemCount] = item.getQuantity() * item.getUnitPrice(); // Calculate the total cost for the item
        itemCount++; // Increment the item count
    } else {
        // Handle error: array is full
    }
}

void CostEstimator::removeItem(const std::string& itemName) {
    for (int i = 0; i < itemCount; i++) {
        if (items[i].getName() == itemName) {
            for (int j = i; j < itemCount - 1; j++) {
                items[j] = items[j + 1]; // Shift the items array to remove the item
                totalCosts[j] = totalCosts[j + 1]; // Shift the totalCosts array to remove the corresponding total cost
            }
            itemCount--; // Decrement the item count
            break;
        }
    }
}

void CostEstimator::clearItems() {
    itemCount = 0; // Reset the item count to zero
}

void CostEstimator::saveItems() const {
    std::ofstream file("items.txt"); // Open the file for writing
    for (int i = 0; i < itemCount; i++) {
        file << items[i].getName() << " " // Write the item name
             << items[i].getQuantity() << " " // Write the item quantity
             << items[i].getUnitPrice() << "\n"; // Write the item unit price
    }
    file.close(); // Close the file
}

void CostEstimator::showEstimates() const {
    double finalTotal = 0.0;
    for (int i = 0; i < itemCount; i++) {
        std::cout << "Item: " << items[i].getName()
                  << ", Quantity: " << items[i].getQuantity()
                  << ", Unit Price: " << items[i].getUnitPrice()
                  << ", Total Cost: " << totalCosts[i] << "\n";
        finalTotal += totalCosts[i]; // Add the total cost of the current item to the final total
    }
    std::cout << "Final Total: " << finalTotal << "\n"; // Print the final total
}

void CostEstimator::loadItems() {
    std::ifstream file("items.txt"); // Open the file for reading
    std::string name;
    int quantity;
    double unit_price;
    while (file >> name >> quantity >> unit_price) {
        addItem(Item(name, quantity, unit_price)); // Add each item from the file to the items array
    }
    file.close(); // Close the file
}