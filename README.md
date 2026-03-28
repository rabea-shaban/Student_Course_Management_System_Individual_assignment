# 🎓 Student Course Management System

A console-based **Student Course Management System** developed using **C++**.  
This project demonstrates the use of **Object-Oriented Programming (OOP)** and **Standard Template Library (STL)** to manage students and their enrolled courses efficiently.

---

## 📌 Overview

This system allows users to:

- Add new students
- Remove existing students
- Search students by ID
- Display all students
- Enroll students in courses
- Show student courses
- Sort students based on GPA

---

## 🧩 UML Class Diagram

```mermaid
classDiagram

class Person {
  - string name
  + Person(string n)
  + getName() string
}

class Student {
  - int id
  - double gpa
  - set<string> courses
  + Student(int i, string n, double g)
  + getId() int
  + getGpa() double
  + addCourse(string course)
  + showCourses()
  + display()
}

class System {
  - vector<Student> students
  + addStudent()
  + removeStudent(id)
  + findStudent(id) Student*
  + displayAll()
  + sortStudents()
}

Person <|-- Student
System --> Student : manages
````

---

## 🔄 Flowchart

```mermaid
flowchart TD
A[Start] --> B[Menu]
B --> C{Choice}

C -->|Add| D[Enter Student Data] --> B
C -->|Remove| E[Enter ID] --> B
C -->|Search| F[Enter ID] --> G[Show Result] --> B
C -->|Display| H[Show All Students] --> B
C -->|Enroll| I[Enter ID & Course] --> B
C -->|Exit| J[End]
```

---

## 🧠 OOP Concepts Used

* **Inheritance** → `Student` inherits from `Person`
* **Encapsulation** → Controlled access via methods
* **Abstraction** → Separation of logic into classes
* **STL Usage** → `vector`, `set`, `algorithm`

---

## ⚙️ Features

### ✅ Add Student

* Input: ID, Name, GPA
* GPA validation (0–4)

### ✅ Remove Student

* Remove student using ID

### ✅ Search Student

* Display student details

### ✅ Display All Students

* Loop through and print all students

### ✅ Enroll Course

* Add course using `set` (no duplicates)

### ✅ Show Courses

* Display all enrolled courses

### ✅ Sort Students

* Sort by GPA (descending)

---

## 🔍 Implementation Details

### 📌 Data Storage

```cpp
vector<Student> students;
```

### 📌 Searching

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

* `set<string>` ensures no duplicate courses

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

* No database (data is lost after program ends)
* Name input does not support spaces
* Linear search (not optimal for large data)

---

## 🚀 Future Improvements

* Add database integration (MongoDB / MySQL)
* Support full names using `getline`
* Use `map` for faster searching
* Build GUI or Web version
* Add authentication system
* Add course grades and credits

---

## 🧑‍💻 Author

**Rabea Shaban**
Frontend Developer (React.js | Next.js | TypeScript)

* 🌐 [https://rabea-shaban.com](https://rabea-shaban.com)
* 💼 [https://www.linkedin.com/in/rabea-sh-elzayat](https://www.linkedin.com/in/rabea-sh-elzayat)
* 🐙 [https://github.com/rabea-shaban](https://github.com/rabea-shaban)

