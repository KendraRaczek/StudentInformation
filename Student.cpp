#include <iostream>
#include "Student.hpp"

// static variables
int Student::numStudents = 0;

// parameterised constructor
Student::Student(std::string name,
std::vector<double> &assignmentsScore,
double projectScore) {
    this -> name = name;
    this -> assignmentsScore = assignmentsScore;
    this -> projectScore = projectScore;
    id = numStudents;
    numStudents++;
}

int Student::getId() {
    return id;
}

std::string Student::getName() {
    return name;
}

std::vector<double>& Student::getAssignmentsScore() {
    return assignmentsScore;
}

double Student::getProjectScore() {
    return projectScore;
}

// static
int Student::getNumStudents() {
    return numStudents;
}

// virtual
void Student::printDetails() {
    std::cout << "STUDENT DETAILS:" << std::endl;
    std::cout << "Id = " << id << std::endl;
    std::cout << "Name = " << name << std::endl;
    std::cout << "Assignments = [";
    for (auto iter = assignmentsScore.begin(); iter != assignmentsScore.end(); iter++) {
        if (iter != assignmentsScore.begin()) std::cout << ", ";
        std::cout << *iter;
    }
    std::cout << "]" << std::endl;
    std::cout << "Project = " << projectScore << std::endl;
    std::cout << "Total = " << getTotal() << std::endl;
    std::cout << "Grade = " << getGrade() << std::endl;
}