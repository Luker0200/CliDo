#include <iostream>
#include <string>
#include "data\variables.cpp"
#include "data\custom_objects.cpp"

void setupProgram() {
    std::cout << "User Called: setupProgram()\n";
    std::cout << "To Get Started, Please Enter The Amount Of Goals You Would Like To Accomplish Today: \n\n";
    std::cin >> setup_taskcount;
    
    std::cout << "I Can Tell That You Are a High Performer... - Currently " << setup_taskcount << " Tasks Exist Between You and Glory.\n\n";

    for (int i = 0; i < setup_taskcount; i++) {
        std::cout << "Please Type the Name of Task " << i + 1 << ": \n"; 

        std::string newUserTaskName;
        std::getline(std::cin >> std::ws, newUserTaskName);

        userTasks.push_back(UserTask(newUserTaskName));
    }

    // Display Task Objectse User Just Stored Along With Their Metadata
    std::cout << "\n-----------------------------------";
    std::cout << "\nHere Are The Tasks You Input: \n";

        for (const auto &task : userTasks) {
            std::cout << '\n';
            std::cout << "Task Name: " << task.getName() 
                    << " | Completed: " << task.getIsComplete() << "\n";
        }
}

void viewProgram() {
    std::cout << "Mark Complete Function Called.\n";
}

void displayFeatures() {
    std::cout << "Remove Entry Function Called.\n";
}

void exitProgram() {
    std::cout << "Exit Program Function Called.\n";
}