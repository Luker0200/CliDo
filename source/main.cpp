#include <iostream>
#include "program_functions.cpp"

int main() {
    std::cout << "Welcome to CliDo - A Digital Second Brain.\n\n";
    
    // Main Menu
    int choice;
        std::cout << "--- Input '1 - 4' to Operate This Program. \n\n";
        std::cout << "1. Setup Program\t\t2. View Program\t\t3. Display Current Features\t\t4. Exit\n";

            std::cin >> choice;
            // Switch Statement to Direct Program to @Functions Based on User Input
            // ---------------------------------------------------------
            switch (choice) {
                case 1:
                    setupProgram();
                    break;
                case 2:
                    viewProgram();
                    break;
                case 3:
                    displayFeatures();
                    break;
                case 4:
                    exitProgram();
                    break;
                default:
                    std::cout << "Invalid Numerical Entry. Please Try Again.\n";
                    break;
            }
    return 0;
}
