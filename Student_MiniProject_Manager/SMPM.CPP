#include <iostream>
#include <string>
#include <vector>

class Task {
public:
    Task(const std::string& name, const std::string& description)
            : name_(name), description_(description), isCompleted_(false) {}

    void markAsCompleted() {
        isCompleted_ = true;
    }

    void display() const {
        std::cout << "Task Name: " << name_ << std::endl;
        std::cout << "Description: " << description_ << std::endl;
        std::cout << "Status: " << (isCompleted_ ? "Completed" : "Pending") << std::endl;
    }

private:
    std::string name_;
    std::string description_;
    bool isCompleted_;
};

class Project {
public:
    Project(const std::string& name, const std::string& description)
            : name_(name), description_(description) {}

    void addTask(const Task& task) {
        tasks_.push_back(task);
    }

    void displayTasks() const {
        std::cout << "Tasks for Project: " << name_ << std::endl;
        for (const Task& task : tasks_) {
            task.display();
            std::cout << "-----------------------------" << std::endl;
        }
    }

private:
    std::string name_;
    std::string description_;
    std::vector<Task> tasks_;
};

int main() {
    Task task1("Task 1", "Complete coding");
    Task task2("Task 2", "Write documentation");
    Task task3("Task 3", "Run tests");

    Project project("Sample Project", "A simple project for demonstration");

    project.addTask(task1);
    project.addTask(task2);
    project.addTask(task3);

    project.displayTasks();

    std::cout << "Marking Task 1 as completed..." << std::endl;
    task1.markAsCompleted();

    project.displayTasks();

    return 0;
}
