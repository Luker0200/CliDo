// Library Imports
#include <iostream>

// File Imports
#include "task-functions.cpp"
#include "virtual_terminal_process.cpp"

//=================================================================================================

int main() {

    enableVirtualTerminalProcessing(); 
    loadTasks();

    std::cout << '\n' << '\n';
    std::cout << "\033[38;5;214mWelcome to Clido - A Digital Second Brain.\033[0m\n";

    int choice;
        do {
            cout << "\n\033[1;34mControl Panel\033[0m\n";
            cout << "1. Add Task\n";
            cout << "2. View Tasks\n";
            cout << "3. Mark Task as Completed\n";
            cout << "4. Delete Task\n";
            cout << "5. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;
            
            switch (choice) {
                case 1: addTask(); break;
                case 2: viewTasks(); break;
                case 3: markCompleted(); break;
                case 4: deleteTask(); break;
                case 5: cout << "Exiting...\n"; break;
                default: cout << "Invalid option!\n";
            }
        } while (choice != 5);
    
    return 0;
}
