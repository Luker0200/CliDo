#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "task-object.cpp"

using namespace std;

void saveTasks() {
    ofstream file("build/taskdata.todo");
    for (const auto& task : tasks) {
        file << task.name << "|" << task.priority << "|" << task.completed << "|" << task.deleted << "\n";
    }
    file.close();
}

void loadTasks() {
    ifstream file("build/taskdata.todo");
    string name, priority;
    bool completed, deleted;
    tasks.clear();
    
    while (getline(file, name, '|') && getline(file, priority, '|') && file >> completed && file.ignore() && file >> deleted && file.ignore()) {
        tasks.push_back({name, priority, completed, deleted});
    }
    
    file.close();
}

void addTask() {
    string name, priority;
    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, name);
    
    cout << "Enter priority (Low, Medium, High): ";
    cin >> priority;
    
    tasks.push_back({name, priority, false, false});
    saveTasks();
    cout << "Task added successfully!\n";
}

void viewTasks() {
    cout << "\n\033[1;36mYour To-Do List:\033[0m\n";
    
    // consistent column widths
    const int idWidth = 5;
    const int taskWidth = 30;
    const int priorityWidth = 15;
    const int statusWidth = 15;
    
    // Header
    cout << left 
         << setw(idWidth) << "ID" 
         << setw(taskWidth) << "Task"
         << setw(priorityWidth) << "Priority"
         << setw(statusWidth) << "Status" << "\n";
    
    // Separator line
    cout << string(idWidth + taskWidth + priorityWidth + statusWidth, '-') << "\n";

    // content rows
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (!tasks[i].deleted) {
            cout << left
                 << setw(idWidth) << (i + 1)
                 << tasks[i].getColor()
                 << setw(taskWidth) << tasks[i].name 
                 << setw(priorityWidth) << tasks[i].priority 
                 << setw(statusWidth) << (tasks[i].completed ? "✔ Completed" : "⏳ Pending") 
                 << "\033[0m\n";
        }
    }
}

void markCompleted() {
    int id;
    cout << "Enter task ID to mark as completed: ";
    cin >> id;
    
    if (id > 0 && id <= (int)tasks.size() && !tasks[id - 1].deleted) {
        tasks[id - 1].completed = true;
        saveTasks();
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid ID!\n";
    }
}

void deleteTask() {
    int id;
    cout << "Enter task ID to delete: ";
    cin >> id;
    
    if (id > 0 && id <= (int)tasks.size()) {
        tasks[id - 1].deleted = true;
        saveTasks();
        cout << "Task deleted!\n";
    } else {
        cout << "Invalid ID!\n";
    }
}