#include <string>
#include <vector>

class UserTask {
    
private:
    std::string UserTaskName;
    bool isComplete;

public:
    // Constructor
    UserTask(const std::string& newUserTaskName) : UserTaskName(newUserTaskName), isComplete(false) {}

    // Getters
    std::string getName() const {
        return UserTaskName;
    }
    std::string getIsComplete() const {
        return isComplete ? "Yes" : "No";
    }

    // Setters
    void setName(const std::string& newUserTaskName) {
        this-> UserTaskName = newUserTaskName;
    }

};

std::vector<UserTask> userTasks;
