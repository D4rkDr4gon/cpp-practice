<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    std::vector<double> grades;
    double average;
    std::string letterGrade;
};

std::string calculateLetterGrade(double average) {
    if (average >= 90) {
        return "A";
    } else if (average >= 80) {
        return "B";
    } else if (average >= 70) {
        return "C";
    } else if (average >= 60) {
        return "D";
    } else {
        return "F";
    }
}

void calculateAverage(Student& student) {
    double sum = 0;
    for (double grade : student.grades) {
        sum += grade;
    }
    student.average = sum / student.grades.size();
    student.letterGrade = calculateLetterGrade(student.average);
}

int main() {
    int numStudents, numSubjects;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;
    std::cout << "Enter the number of subjects: ";
    std::cin >> numSubjects;

    std::vector<Student> students(numStudents);

    for (int i = 0; i < numStudents; i++) {
        std::cout << "Enter the name of student " << i + 1 << ": ";
        std::cin >> students[i].name;

        students[i].grades.resize(numSubjects);

        for (int j = 0; j < numSubjects; j++) {
            std::cout << "Enter the grade for subject " << j + 1 << " of student " << i + 1 << ": ";
            std::cin >> students[i].grades[j];
        }

        calculateAverage(students[i]);
    }

    std::cout << "Student Grades:\n";
    for (const Student& student : students) {
        std::cout << "Name: " << student.name << ", Average Grade: " << student.average << ", Letter Grade: " << student.letterGrade << "\n";
    }

    return 0;
}
=======
#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    std::vector<double> grades;
    double average;
    std::string letterGrade;
};

std::string calculateLetterGrade(double average) {
    if (average >= 90) {
        return "A";
    } else if (average >= 80) {
        return "B";
    } else if (average >= 70) {
        return "C";
    } else if (average >= 60) {
        return "D";
    } else {
        return "F";
    }
}

void calculateAverage(Student& student) {
    double sum = 0;
    for (double grade : student.grades) {
        sum += grade;
    }
    student.average = sum / student.grades.size();
    student.letterGrade = calculateLetterGrade(student.average);
}

int main() {
    int numStudents, numSubjects;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;
    std::cout << "Enter the number of subjects: ";
    std::cin >> numSubjects;

    std::vector<Student> students(numStudents);

    for (int i = 0; i < numStudents; i++) {
        std::cout << "Enter the name of student " << i + 1 << ": ";
        std::cin >> students[i].name;

        students[i].grades.resize(numSubjects);

        for (int j = 0; j < numSubjects; j++) {
            std::cout << "Enter the grade for subject " << j + 1 << " of student " << i + 1 << ": ";
            std::cin >> students[i].grades[j];
        }

        calculateAverage(students[i]);
    }

    std::cout << "Student Grades:\n";
    for (const Student& student : students) {
        std::cout << "Name: " << student.name << ", Average Grade: " << student.average << ", Letter Grade: " << student.letterGrade << "\n";
    }

    return 0;
}
>>>>>>> 71f08df9028c5fab6502c73439930f78338fb0e8
