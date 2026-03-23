#include "Student.h"

Student::Student(int i, string n, double g) : Person(n) {
    id = i;
    gpa = g;
}

int Student::getId() {
    return id;
}

double Student::getGpa() {
    return gpa;
}

void Student::addCourse(string course) {
    courses.insert(course);
}

void Student::showCourses() {
    for (auto c : courses) {
        cout << c << endl;
    }
}

void Student::display() {
    cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
}