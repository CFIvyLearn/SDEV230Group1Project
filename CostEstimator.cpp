#include "CostEstimator.h"
#include <fstream>
#include <algorithm>
#include <iostream>

void CostEstimator::addItem(const Item& item) {
    items.push_back(item);
}

void CostEstimator::removeItem(const std::string& itemName) {
    items.erase(std::remove_if(items.begin(), items.end(), 
        [&itemName](const Item& item) { return item.getName() == itemName; }), items.end());
}

void CostEstimator::clearItems() {
    items.clear();
}

void CostEstimator::saveItems() const {
    std::ofstream file("items.txt");
    for (const auto& item : items) {
        file << item.getName() << " " << item.getQuantity() << " " << item.getUnitPrice() << "\n";
    }
    file.close();
}

void CostEstimator::showEstimates() const {
    double totalCost = 0.0;
    for (const auto& item : items) {
        totalCost += item.getQuantity() * item.getUnitPrice();
    }
    std::cout << "Total cost: " << totalCost << "\n";
}

void CostEstimator::loadItems() {
    std::ifstream file("items.txt");
    std::string name;
    int quantity;
    double unit_price;
    while (file >> name >> quantity >> unit_price) {
        items.push_back(Item(name, quantity, unit_price));
    }
    file.close();
}