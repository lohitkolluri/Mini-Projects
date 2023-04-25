#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Project {
public:
    Project(const string& rollNumber, const string& name, int marks)
            : rollNumber_(rollNumber), name_(name), marks_(marks) {}
    string getRollNumber() const { return rollNumber_; }
    string getName() const { return name_; }
    int getMarks() const { return marks_; }
    void setMarks(int marks) { marks_ = marks; }

private:
    string rollNumber_;
    string name_;
    int marks_;
};

void displayMenu() {
    cout << "1. Add Project\n";
    cout << "2. View Projects\n";
    cout << "3. Edit Marks\n";
    cout << "4. Quit\n";
    cout << "Enter your choice: ";
}

void clearScreen() {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear");
#endif
}

int main() {
    vector<Project> projects;
    int choice;

    while (true) {
        clearScreen();
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string rollNumber, name;
                int marks;
                cout << "Enter roll number: ";
                cin >> rollNumber;
                cout << "Enter project name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter project marks: ";
                cin >> marks;
                Project project(rollNumber, name, marks);
                projects.push_back(project);
                cout << "Project added successfully.\n";
                break;
            }
            case 2: {
                if (projects.empty()) {
                    cout << "No projects available.\n";
                } else {
                    cout << "Projects:\n";
                    for (size_t i = 0; i < projects.size(); ++i) {
                        cout << "Roll Number: " << projects[i].getRollNumber()
                             << ", Name: " << projects[i].getName()
                             << ", Marks: " << projects[i].getMarks() << endl;
                    }
                }
                break;
            }
            case 3: {
                if (projects.empty()) {
                    cout << "No projects available.\n";
                } else {
                    string rollNumber;
                    int newMarks;
                    cout << "Enter roll number to edit marks: ";
                    cin >> rollNumber;

                    bool found = false;
                    for (auto& project : projects) {
                        if (project.getRollNumber() == rollNumber) {
                            cout << "Enter new marks: ";
                            cin >> newMarks;
                            project.setMarks(newMarks);
                            cout << "Marks updated successfully.\n";
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Project not found.\n";
                    }
                }
                break;
            }
            case 4: {
                cout << "Exiting...\n";
                return 0;
            }
            default: {
                cout << "Invalid choice. Try again.\n";
                break;
            }
        }

        cout << "Press enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
