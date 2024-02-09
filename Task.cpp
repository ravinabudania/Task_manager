#include <iostream>
#include <vector>

using namespace std;

// Task structure to represent each task
struct Task {
    string description;
    bool completed;
};

// Function to display the menu options
void displayMenu() {
    cout << "\nTask Manager Menu:\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Quit\n";
}

int main() {
    vector<Task> tasks; // Vector to store tasks

    while (true) {
        displayMenu(); // Display menu options

        int choice;
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Task newTask;
                cout << "Enter task description: ";
                cin.ignore(); // Ignore any newline characters in the buffer
                getline(cin, newTask.description);
                newTask.completed = false;
                tasks.push_back(newTask);
                cout << "Task added successfully!\n";
                break;
            }
            case 2: {
                cout << "\nTask List:\n";
                if (tasks.empty()) {
                    cout << "No tasks available.\n";
                } else {
                    for (size_t i = 0; i < tasks.size(); ++i) {
                        cout << i + 1 << ". ";
                        cout << (tasks[i].completed ? "[Completed] " : "[Pending] ");
                        cout << tasks[i].description << endl;
                    }
                }
                break;
            }
            case 3: {
                int taskIndex;
                cout << "Enter the task number to mark as completed: ";
                cin >> taskIndex;

                if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
                    tasks[taskIndex - 1].completed = true;
                    cout << "Task marked as completed!\n";
                } else {
                    cout << "Invalid task number.\n";
                }
                break;
            }
            case 4: {
                cout << "Exiting Task Manager. Goodbye!\n";
                return 0;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}
