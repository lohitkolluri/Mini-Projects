#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <limits>

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
    cout << "====================================" << endl;
    cout << setw(18) << "STUDENT PROJECT MANAGER" << endl;
    cout << "====================================" << endl;
    cout << "1. Add Project" << endl;
    cout << "2. View Projects" << endl;
    cout << "3. Edit Marks" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ";
}

void clearScreen() {
#ifdef _WIN32

#else
    system("clear");
#endif
}

void displayProjects(const vector<Project>& projects) {
    cout << "====================================" << endl;
    cout << setw(18) << "VIEW PROJECTS" << endl;
    cout << "====================================" << endl;
    cout << left << setw(15) << "Roll Number" << setw(20) << "Name" << setw(10) << "Marks" << endl;
    cout << "------------------------------------" << endl;
    for (const Project& project : projects) {
        cout << left << setw(15) << project.getRollNumber() << setw(20) << project.getName() << setw(10)
             << project.getMarks() << endl;
    }
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
                cout << "Enter Roll Number: ";
                cin.ignore();
                getline(cin, rollNumber);
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Marks: ";
                cin >> marks;
                projects.emplace_back(rollNumber, name, marks);
                cout << "Project added successfully!" << endl;
                break;
            }
            case 2: {
                displayProjects(projects);
                break;
            }
            case 3: {
                string rollNumber;
                int newMarks;
                cout << "Enter Roll Number: ";
                cin.ignore();
                getline(cin, rollNumber);
                bool found = false;
                for (Project& project : projects) {
                    if (project.getRollNumber() == rollNumber) {
                        found = true;
                        cout << "Enter New Marks: ";
                        cin >> newMarks;
                        project.setMarks(newMarks);
                        cout << "Marks updated successfully!" << endl;
                        break;
                    }
                }
                if (!found) {
                    cout << "Project with Roll Number " << rollNumber << " not found." << endl;
                }
                break;
            }
            case 4: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice, please enter a valid choice." << endl;
                break;
            }
        }

        cout << endl;
        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    return 0;
}
