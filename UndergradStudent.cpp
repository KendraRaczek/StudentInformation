#include <iostream>
#include <numeric>
#include "UndergradStudent.hpp"

// constructor - calls superclass constructor
UndergradStudent::UndergradStudent(std::string name,
std::vector<double> &assignmentsScore,
double projectScore, std::string residenceHall,
std::string yearInCollege)
: Student(name, assignmentsScore, projectScore),
  residenceHall(residenceHall), yearInCollege(yearInCollege){

}

std::string UndergradStudent::getResidenceHall() {
    return residenceHall;
}

std::string UndergradStudent::getYearInCollege() {
    return yearInCollege;
}

// virtual
void UndergradStudent::printDetails() {
    // call superclass printDetails
    Student::printDetails();
    std::cout << "Type = Undergraduate Student" << std::endl;
    std::cout << "Residence Hall = " << residenceHall << std::endl;
    std::cout << "Year in College = " << yearInCollege << std::endl;
}

// virtual
double UndergradStudent::getTotal() {
    double avgAssignmentsScore;
    double projectScore = getProjectScore();

    // calculate avg assignments score
    avgAssignmentsScore = (std::accumulate(getAssignmentsScore().begin(),
                                           getAssignmentsScore().end(), 0.0))
                          / getAssignmentsScore().size();

    double total = avgAssignmentsScore * 0.7 + projectScore * 0.3;

    return total;
}

// virtual
std::string UndergradStudent::getGrade() {
    std::string grade;
    if (getTotal() < 70) {
        grade = "N";
    }
    else {
        grade = "CR";
    }
    return grade;
}