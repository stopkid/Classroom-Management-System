#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    Student(const std::string& name) : name(name), grades() {}

    void addGrade(double grade) {
        grades.push_back(grade);
    }

    void editGrade(int index, double newGrade) {
        if (index >= 0 && index < grades.size()) {
            grades[index] = newGrade;
        } else {
            std::cout << "Invalid grade index." << std::endl;
        }
    }

    double calculateGPA() const {
        if (grades.empty()) return 0.0;
        double sum = 0.0;
        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }

    void printInfo() const {
        std::cout << "Student: " << name << ", GPA: " << calculateGPA() << std::endl;
    }

public:
    std::string getName() const {
        return name;
    }

private:
    std::string name;
    std::vector<double> grades;
};

class Classroom {
public:
    void addStudent(const std::string& name) {
        students.push_back(Student(name));
    }

    Student* getStudent(const std::string& name) {
        for (Student& student : students) {
            if (student.getName() == name) {
                return &student;
            }
        }
        return nullptr;
    }

    void printAllStudents() const {
        for (const Student& student : students) {
            student.printInfo();
        }
    }

private:
    std::vector<Student> students;
};

int main() {
    Classroom classroom;
    int choice;
    std::string name;
    double grade;
    int index;

    while (true) {
        std::cout << "1. Add Student\n2. Add Grade\n3. Edit Grade\n4. Print All Students\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter student name: ";
                std::cin >> name;
                classroom.addStudent(name);
                break;
            case 2:
                std::cout << "Enter student name: ";
                std::cin >> name;
                if (Student* student = classroom.getStudent(name)) {
                    std::cout << "Enter grade: ";
                    std::cin >> grade;
                    student->addGrade(grade);
                } else {
                    std::cout << "Student not found." << std::endl;
                }
                break;
            case 3:
                std::cout << "Enter student name: ";
                std::cin >> name;
                if (Student* student = classroom.getStudent(name)) {
                    std::cout << "Enter grade index: ";
                    std::cin >> index;
                    std::cout << "Enter new grade: ";
                    std::cin >> grade;
                    student->editGrade(index, grade);
                } else {
                    std::cout << "Student not found." << std::endl;
                }
                break;
            case 4:
                classroom.printAllStudents();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    }
}