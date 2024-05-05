#include "CostEstimator.h"
#include <fstream>
#include <algorithm>

void CostEstimator::addItem(const Item& item) {
    items.push_back(item);
    std::cout << "Item added successfully.\n";
}

void CostEstimator::removeItem(const std::string& itemName) {
    auto it = std::remove_if(items.begin(), items.end(), [&itemName](const Item& item) {
        return item.name == itemName;
    });
    items.erase(it, items.end());
    std::cout << "Item removed.\n";
}

void CostEstimator::clearItems() {
    items.clear();
    std::cout << "All items cleared.\n";
}

void CostEstimator::saveItems() const {
    std::ofstream file("cost_estimate.txt");
    for (const auto& item : items) {
        file << item.name << " " << item.quantity << " " << item.unit_price << "\n";
    }
    file.close();
    std::cout << "Items saved to file.\n";
}

void CostEstimator::showEstimates() const {
    double totalCost = 0;
    for (const auto& item : items) {
        totalCost += item.getTotalCost();
        std::cout << item.name << ": " << item.quantity << " * $" << item.unit_price << " = $" << item.getTotalCost() << "\n";
    }
    std::cout << "Total Cost: $" << totalCost << "\n";
}

void CostEstimator::loadItems() {
    std::ifstream file("cost_estimate.txt");
    std::string name;
    int quantity;
    double unit_price;
    while (file >> name >> quantity >> unit_price) {
        items.push_back(Item(name, quantity, unit_price));
    }
    file.close();
    std::cout << "Items loaded from file.\n";
}
