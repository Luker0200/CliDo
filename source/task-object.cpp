
#include <string>
#include <vector>

using namespace std;

struct Task {
    string name;
    string priority;
    bool completed;
    bool deleted;

    string getColor() const {
        if (priority == "High") return "\033[1;31m";  // Red
        if (priority == "Medium") return "\033[1;33m"; // Yellow
        if (priority == "Low") return "\033[1;32m"; // Green
        return "\033[0m"; // Default
    }
};

vector<Task> tasks;