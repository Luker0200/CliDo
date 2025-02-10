#include <iostream>
#include "functions.cpp"
#include "variables.cpp"

int main() {
    std::cout << "Welcome to CliDo - A Life Management Tool.\n\n";
    std::cout << "To Get Started, Please Enter The Amount Of Goals You Would Like To Accomplish Today:\n";

            std::cin >> taskcount;
    
    std::cout << "\nI see your a high preformer... You are " << taskcount << " tasks closer to glory.\n";

    int choice;
        std::cout << "Input '1 - 4' to Operate This Program. \n\n";
        std::cout << "1. View Daily Goals\t\t2. Mark Entry Complete\t\t3. Remove Entry\t\t4. Exit\n";

            std::cin >> choice;
            // Switch Statement to Call Functions Based on User Input
            // -------------------------------------------------------
            switch (choice) {
                case 1:
                    viewGoals();
                    break;
                case 2:
                    markComplete();
                    break;
                case 3:
                    removeEntry();
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
