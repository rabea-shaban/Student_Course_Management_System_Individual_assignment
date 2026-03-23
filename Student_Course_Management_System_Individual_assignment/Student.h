#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <set>
#include <iostream>
using namespace std;

class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses;

public:
    Student(int i, string n, double g);

    int getId();
    double getGpa();

    void addCourse(string course);
    void showCourses();
    void display();
};

#endif