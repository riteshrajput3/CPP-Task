using namespace std;
#include <iostream>
#include <vector>

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task>& tasks, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found." << endl;
        return;
    }
    
    cout << "Tasks:" << endl;
    for (const Task& task : tasks) {
        cout << "- " << task.description;
        if (task.completed) {
            cout << " (completed)";
        }
        cout << endl;
    }
}

void markTaskAsCompleted(vector<Task>& tasks, int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(vector<Task>& tasks, int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
 vector<Task> tasks;
    
    while (true) {
     cout << "Choose an option:" <<endl;
     cout << "1. Add Task" <<endl;
     cout << "2. View Tasks" <<endl;
     cout << "3. Mark Task as Completed" <<endl;
     cout << "4. Remove Task" <<endl;
     cout << "5. Exit" <<endl;
        
        int option;
     cin >> option;
        
        if (option == 1) {
         cout << "Enter task description: ";
         string description;
         cin.ignore();
         getline(std::cin, description);
            addTask(tasks, description);
        } else if (option == 2) {
            viewTasks(tasks);
        } else if (option == 3) {
         cout << "Enter task index: ";
            int index;
         cin >> index;
            markTaskAsCompleted(tasks, index);
        } else if (option == 4) {
         cout << "Enter task index: ";
            int index;
         cin >> index;
            removeTask(tasks, index);
        } else if (option == 5) {
            break;
        } else {
         cout << "Invalid option." <<endl;
        }
        
     cout <<endl;
    }
    
    return 0;
}

 