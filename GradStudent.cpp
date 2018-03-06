#include <iostream>
#include <numeric>
#include "GradStudent.hpp"

// constructor - calls superclass constructor
GradStudent::GradStudent(std::string name,
std::vector<double>& assignmentsScore,
double projectScore,
        std::string researchArea,
std::string advisor)
: Student(name, assignmentsScore, projectScore),
  researchArea(researchArea), advisor(advisor) {

}

std::string GradStudent::getResearchArea() {
    return researchArea;
}

std::string GradStudent::getAdvisor() {
    return advisor;
}

// virtual
void GradStudent::printDetails() {
    // call superclass printDetails
    Student::printDetails();
    std::cout << "Type = Graduate Student" << std::endl;
    std::cout << "Research Area = " << researchArea << std::endl;
    std::cout << "Advisor = " << advisor << std::endl;
}

// virtual
double GradStudent::getTotal() {
    double avgAssignmentsScore;
    double projectScore = getProjectScore();

    // calculate avg assignments score
    avgAssignmentsScore = (std::accumulate(getAssignmentsScore().begin(),
                                           getAssignmentsScore().end(), 0.0))
                          / getAssignmentsScore().size();

    double total = avgAssignmentsScore * 0.5 + projectScore * 0.5;

    return total;
}

// virtual
std::string GradStudent::getGrade() {
    std::string grade;
    if (getTotal() < 80) {
        grade = "N";
    }
    else {
        grade = "CR";
    }
    return grade;
}