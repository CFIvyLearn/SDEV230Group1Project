#include "CostEstimator.h"
#include <fstream>
#include <algorithm>
#include <iostream>

void CostEstimator::addItem(const Item& item) {
    items.push_back(item); // Add an item to the list of items
}

void CostEstimator::removeItem(const std::string& itemName) {
    // Remove an item from the list of items based on its name
    items.erase(std::remove_if(items.begin(), items.end(), 
        [&itemName](const Item& item) { return item.getName() == itemName; }), items.end());
}

void CostEstimator::clearItems() {
    items.clear(); // Clear all items from the list
}

void CostEstimator::saveItems() const {
    std::ofstream file("items.txt"); // Open a file for writing
    for (const auto& item : items) {
        // Write each item's name, quantity, and unit price to the file
        file << item.getName() << " " << item.getQuantity() << " " << item.getUnitPrice() << "\n";
    }
    file.close(); // Close the file
}

void CostEstimator::showEstimates() const {
    double totalCost = 0.0;
    for (const auto& item : items) {
        // Calculate the total cost by multiplying each item's quantity by its unit price
        totalCost += item.getQuantity() * item.getUnitPrice();
    }
    std::cout << "Total cost: " << totalCost << "\n"; // Print the total cost
}

void CostEstimator::loadItems() {
    std::ifstream file("items.txt"); // Open a file for reading
    std::string name;
    int quantity;
    double unit_price;
    while (file >> name >> quantity >> unit_price) {
        // Read each item's name, quantity, and unit price from the file and add it to the list
        items.push_back(Item(name, quantity, unit_price));
    }
    file.close(); // Close the file
}