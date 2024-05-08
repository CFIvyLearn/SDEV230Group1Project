#include "CostEstimator.h"
#include <iostream>
#include <string>


/**
 * WHEN YOU RIN THE PROGRAM RUN IT USING THE FOLLOWING COMMAND LINES:
 * g++ -o main main.cpp CostEstimator.cpp item.h CostEstimator.h  
 * ./main
 * 
 * IT WONT WORK FOR SOME REASON IF YOU RUN IT USING THE RUN BUTTON IN VSCODE
 */


int main() {
    CostEstimator estimator; // Create an instance of the CostEstimator class
    bool running = true; // Variable to control the main loop
    int choice; // Variable to store the user's choice

    while (running) { // Main loop that runs until 'running' is set to false
        std::cout << "\nMenu:\n"; // Display the menu options
        std::cout << "1. Add Item\n";
        std::cout << "2. Remove Item\n";
        std::cout << "3. Show Estimates\n";
        std::cout << "4. Clear All Items\n";
        std::cout << "5. Save Items to File\n";
        std::cout << "6. Load Items from File\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice; // Read the user's choice from the console

        switch (choice) { // Use a switch statement to perform different actions based on the user's choice
            case 1: { // If the user chooses 1
                std::string name;
                int quantity;
                double unit_price;
                std::cout << "Enter item name: ";
                std::cin >> name; // Read the item name from the console
                std::cout << "Enter quantity: ";
                std::cin >> quantity; // Read the item quantity from the console
                std::cout << "Enter unit price: ";
                std::cin >> unit_price; // Read the item unit price from the console
                estimator.addItem(Item(name, quantity, unit_price)); // Add the item to the CostEstimator
                break;
            }
            case 2: { // If the user chooses 2
                std::string name;
                std::cout << "Enter item name to remove: ";
                std::cin >> name; // Read the item name to remove from the console
                estimator.removeItem(name); // Remove the item from the CostEstimator
                break;
            }
            case 3: { // If the user chooses 3
                estimator.showEstimates(); // Show the estimates calculated by the CostEstimator
                break;
            }
            case 4: { // If the user chooses 4
                estimator.clearItems(); // Clear all items in the CostEstimator
                break;
            }
            case 5: { // If the user chooses 5
                estimator.saveItems(); // Save the items in the CostEstimator to a file
                break;
            }
            case 6: { // If the user chooses 6
                estimator.loadItems(); // Load items from a file into the CostEstimator
                break;
            }
            case 7: { // If the user chooses 7
                running = false; // Set 'running' to false to exit the main loop
                std::cout << "Exiting program...\n";
                break;
            }
            default: { // If the user chooses an invalid option
                std::cout << "Invalid choice, please try again.\n";
                break;
            }
        }
    }

    return 0; // Exit the program
}