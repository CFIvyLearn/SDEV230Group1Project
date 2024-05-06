#include "CostEstimator.h"
#include <iostream>
#include <string>

int main() {
    CostEstimator estimator;
    bool running = true;
    int choice;

    while (running) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Remove Item\n";
        std::cout << "3. Show Estimates\n";
        std::cout << "4. Clear All Items\n";
        std::cout << "5. Save Items to File\n";
        std::cout << "6. Load Items from File\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                int quantity;
                double unit_price;
                std::cout << "Enter item name: ";
                std::cin >> name;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                std::cout << "Enter unit price: ";
                std::cin >> unit_price;
                estimator.addItem(Item(name, quantity, unit_price));
                break;
            }
            case 2: {
                std::string name;
                std::cout << "Enter item name to remove: ";
                std::cin >> name;
                estimator.removeItem(name);
                break;
            }
            case 3: {
                estimator.showEstimates();
                break;
            }
            case 4: {
                estimator.clearItems();
                break;
            }
            case 5: {
                estimator.saveItems();
                break;
            }
            case 6: {
                estimator.loadItems();
                break;
            }
            case 7: {
                running = false;
                std::cout << "Exiting program...\n";
                break;
            }
            default: {
                std::cout << "Invalid choice, please try again.\n";
                break;
            }
        }
    }

    return 0;
}