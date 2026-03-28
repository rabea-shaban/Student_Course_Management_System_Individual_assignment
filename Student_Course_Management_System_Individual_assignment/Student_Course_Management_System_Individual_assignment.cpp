#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

vector<Student> students;

Student* findStudent(int id) {
    for (auto& s : students) {
        if (s.getId() == id)
            return &s;
    }
    return nullptr;
}

void addStudent() {
    int id;
    string name;
    double gpa;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter GPA (0 - 4): ";
    cin >> gpa;

    if (gpa < 0 || gpa > 4) {
        cout << "Invalid GPA!\n";
        return;
    }

    students.push_back(Student(id, name, gpa));
    cout << "Student added successfully.\n";
}

void removeStudent() {
    int id;
    cout << "Enter Student ID to remove: ";
        cin >> id;

    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->getId() == id) {
            students.erase(it);
            cout << "Student removed successfully.\n";
            return;
        }
    }

    cout << "Not Found \n";
}

void enrollCourse() {
    int id;
    string course;
    cout << "Enter Student ID to enroll in a course: ";

    cin >> id;

    Student* s = findStudent(id);

    if (!s) {
        cout << "Not Found \n";
        return;
    }
    cout << "Enter Courses Cursess Name : ";
    cin >> course;
    s->addCourse(course);
}

void showCourses() {
    int id;
    cout << "Enter Student ID to show courses: ";

    cin >> id;

    Student* s = findStudent(id);

    if (!s) {
        cout << "Not Found \n";
        return;
    }

    s->showCourses();
}

void displayAll() {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    cout << "\n=== Students List ===\n";
    for (auto& s : students) {
        s.display();
    }
}

void sortStudents() {
    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.getGpa() > b.getGpa();
        });
    cout << "Students sorted by GPA (Descending).\n";

}

int main() {
    int choice;

    while (true) {
        cout << "\n========== MENU ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Enroll in Course\n";
        cout << "6. Show Courses\n";
        cout << "7. Sort Students\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";


        cin >> choice;

        switch (choice) {
        case 1: addStudent(); displayAll(); break;
        case 2: removeStudent(); displayAll(); break;
        case 3: {
            int id;
            cout << "Enter Student ID to search: ";

            cin >> id;
            Student* s = findStudent(id);
            if (s) s->display();
            else cout << "Not Found \n";
            break;
        }
        case 4: displayAll(); break;
        case 5: enrollCourse(); break;
        case 6: showCourses(); break;
        case 7: sortStudents(); displayAll(); break;
        case 8: return 0;
        default: cout << "Invalid \n";
        }
    }
}