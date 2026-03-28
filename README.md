# 🎓 Student Course Management System

A simple **C++ console-based application** for managing students and their enrolled courses.  
The project demonstrates core **Object-Oriented Programming (OOP)** concepts and usage of the **Standard Template Library (STL)**.

---

## 📌 Overview

This system allows users to:

- Add and remove students
- Search for a student by ID
- Enroll students in courses
- Display all students
- Show courses for a specific student
- Sort students by GPA

---

## 🏗️ Project Structure

```

📁 Student_Course_Management_System
│── Person.h / Person.cpp
│── Student.h / Student.cpp
│── main.cpp

````

---

## 🧠 OOP Concepts Used

- **Inheritance** → `Student` inherits from `Person`
- **Encapsulation** → Controlled access using getters
- **Abstraction** → Separation of logic into classes
- **STL Usage** → `vector`, `set`, `algorithm`

---

## ⚙️ Features

### ✅ Add Student
- Input: ID, Name, GPA
- GPA validation (must be between 0 and 4)

### ✅ Remove Student
- Removes student using ID

### ✅ Search Student
- Finds and displays student details

### ✅ Display All Students
- Prints all stored students

### ✅ Enroll Course
- Adds course to student using `set` (no duplicates)

### ✅ Show Courses
- Displays all courses of a student

### ✅ Sort Students
- Sorts students by GPA (descending)

---

## 🧩 Classes

### 🔹 Person Class
```cpp
class Person {
protected:
    string name;

public:
    Person(string n);
    string getName();
};
````

---

### 🔹 Student Class

```cpp
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
```

---

## 🔍 Implementation Details

### 📌 Data Storage

```cpp
vector<Student> students;
```

### 📌 Searching

* Linear search using:

```cpp
Student* findStudent(int id);
```

### 📌 Sorting

```cpp
sort(students.begin(), students.end(), [](Student a, Student b) {
    return a.getGpa() > b.getGpa();
});
```

### 📌 Course Storage

* Uses `set<string>` to prevent duplicates

---

## ▶️ How to Run

### 1. Compile

```bash
g++ main.cpp Student.cpp Person.cpp -o app
```

### 2. Run

```bash
./app
```

---

## 🖥️ Menu

```
1.Add
2.Remove
3.Search
4.Display
5.Enroll
6.Show Courses
7.Sort
8.Exit
```

---

## ⚠️ Limitations

* No database or file storage (data is temporary)
* Name input does not support spaces
* Linear search is not efficient for large data

---

## 🚀 Future Improvements

* Add file/database storage
* Support full names (`getline`)
* Replace vector with `map` for faster search
* Build GUI or Web version
* Add authentication system
* Add course grades & credit hours

---

## 🧑‍💻 Author

**Rabea Shaban**
Frontend Developer (React.js | Next.js | TypeScript)

* 🌐 Portfolio: [https://rabea-shaban.com](https://rabea-shaban.com)
* 💼 LinkedIn: [https://www.linkedin.com/in/rabea-sh-elzayat](https://www.linkedin.com/in/rabea-sh-elzayat)
* 🐙 GitHub: [https://github.com/rabea-shaban](https://github.com/rabea-shaban)

---

