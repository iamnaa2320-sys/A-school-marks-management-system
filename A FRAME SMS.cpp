#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    int semester;
    float cgpa;
};

class A FRAME StudentManagementSystem {
private:
    Student students[100]; 
    int count;               

public:
    A FRAME StudentManagementSystem() {
        count = 0;
    }

    void addStudent() {
        if (count >= 100) {
            cout << "Student limit reached"<<endl;
            return;
        }

        cout << "Enter Student ID: "<<endl;
        cin >> students[count].id;
        cin.ignore();

        cout << "Enter Student Name: "<<endl;
        getline(cin, students[count].name);

        cout << "Enter Semester: "<<endl;
        cin >> students[count].semester;

        cout << "Enter CGPA: "<<endl;
        cin >> students[count].cgpa;

        count++;
        cout << "Student added successfully"<<endl";
    }

    void displayStudents() {
        if (count == 0) {
            cout << "No student records found.\n";
            return;
        }

        cout << "Here are the Record of Students <<endl ";
        for (int i = 0; i < count; i++) {
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Semester: " << students[i].semester << endl;
            cout << "CGPA: " << students[i].cgpa << endl;
            
        }
    }

    void searchStudent() {
        int searchId;
        cout << "Enter Student ID to search: ";
        cin >> searchId;

        for (int i = 0; i < count; i++) {
            if (students[i].id == searchId) {
                cout << "Student Found is: ";
                cout << "Name: " << students[i].name << endl;
                cout << "Semester: " << students[i].semester << endl;
                cout << "CGPA: " << students[i].cgpa << endl;
                return;
            }
        }

        cout << "Student not found!";
    }

    void deleteStudent() {
        int deleteId;
        cout << "Enter Student ID to delete: ";
        cin >> deleteId;

        for (int i = 0; i < count; i++) {
            if (students[i].id == deleteId) {
                for (int j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];
                }
                count--;
                cout << "Student record deleted successfully!<<endl";
                return;
            }
        }

        cout << "Student not found <<endl";
    }

    void menu() {
        int choice;
        do {
            cout << "Student Record Management System<<endl";
            cout << "1. Add Student"<<endl;
            cout << "2. Display All Students"<<endl;
            cout << "3. Search Student by ID"<<endl;
            cout << "4. Delete Student"<<endl;
            cout << "5. Exit"<<endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addStudent(); break;
                case 2: displayStudents(); break;
                case 3: searchStudent(); break;
                case 4: deleteStudent(); break;
                case 5: cout << "Exiting program <<endl"; break;
                default: cout << "Invalid choice! Try again"<<endl;
            }
        } while (choice != 5);
    }
};

int main() {
    A FRAME StudentManagementSystem AFsms;
    AFsms.menu();
    return 0;
}
