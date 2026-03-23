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

    cout << "Enter GPA: ";
    cin >> gpa;

    if (gpa < 0 || gpa > 4) {
        cout << "Invalid GPA!\n";
        return;
    }

    students.push_back(Student(id, name, gpa));
    cout << "Added Done\n";
}

void removeStudent() {
    int id;
    cin >> id;

    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->getId() == id) {
            students.erase(it);
            cout << "Removed Done \n";
            return;
        }
    }

    cout << "Not Found \n";
}

void enrollCourse() {
    int id;
    string course;
    cout << "Enter Courses id : ";

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
    cout << "Enter Show Courses id : ";

    cin >> id;

    Student* s = findStudent(id);

    if (!s) {
        cout << "Not Found \n";
        return;
    }

    s->showCourses();
}

void displayAll() {
    for (auto s : students) {
        s.display();
    }
}

void sortStudents() {
    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.getGpa() > b.getGpa();
        });
}

int main() {
    int choice;

    while (true) {
        cout << "\n1.Add\n2.Remove\n3.Search\n4.Display\n5.Enroll\n6.Show Courses\n7.Sort\n8.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: removeStudent(); break;
        case 3: {
            int id;
            cin >> id;
            Student* s = findStudent(id);
            if (s) s->display();
            else cout << "Not Found \n";
            break;
        }
        case 4: displayAll(); break;
        case 5: enrollCourse(); break;
        case 6: showCourses(); break;
        case 7: sortStudents(); break;
        case 8: return 0;
        default: cout << "Invalid \n";
        }
    }
}