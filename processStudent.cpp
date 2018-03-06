///////////////////////////////////////////////////////////////////////////////
// File Name:      processStudent.cpp
//
// Author:         Kendra Raczek
// CS email:       raczek@cs.wisc.edu
//
// Description:    Methods to perform some processing on student objects.
//
// Sources:        Walletfox.com
//
// URL(s) of sources:
//                 http://www.walletfox.com/course/sortvectorofcustomobjects11.php
///////////////////////////////////////////////////////////////////////////////

#include <sstream>
#include <iostream>
#include <algorithm>
#include "processStudent.hpp"

void fillStudents(std::istream &inFile,
                  std::vector<std::shared_ptr<Student>>& gstudentPtrs,
                  std::vector<std::shared_ptr<Student>>& ugstudentPtrs) {

    // all student variables
    std::string studentType;
    std::string name;
    double projectScore;

    // undergrad variables
    std::string residenceHall;
    std::string yearInCollege;

    // grad variables
    std::string researchArea;
    std::string advisor;

    for( std::string line; getline( inFile, line ); ) {

        std::vector<std::string> wordsInLine;
        std::istringstream iss;
        std::vector<double> assignmentsScore;

        // split line by commas
        iss.str(line);
        std::string current;
        while (std::getline(iss, current, ',')) {
            if (current.length() != 0) {
                wordsInLine.push_back(current);
            }
        }

        // all student variables
        studentType = wordsInLine[0];
        name = wordsInLine[1];
        for (int i = 2; i < 8; i++) {
            assignmentsScore.push_back( std::stoi(wordsInLine[i]));
        }
        projectScore = std::stod(wordsInLine[8]);

        // ugrad/grad specific variables
        // ugrad
        if (studentType == "U") {
            residenceHall = wordsInLine[9];
            yearInCollege = wordsInLine[10];
            std::shared_ptr<Student> ugrad (new UndergradStudent
                (name, assignmentsScore, projectScore, residenceHall,
                 yearInCollege));
            ugstudentPtrs.push_back(ugrad);
        }
        // grad
        else {
            researchArea = wordsInLine[9];
            advisor = wordsInLine[10];
            std::shared_ptr<Student> grad (new GradStudent
                (name, assignmentsScore, projectScore, researchArea,
                 advisor));
            gstudentPtrs.push_back(grad);
        }
    }
}

void printStudents(std::vector<std::shared_ptr<Student>>& students) {

    for (auto student : students) {
        student -> printDetails();
        std::cout << std::endl;
    }
}

void computeStatistics(std::vector<std::shared_ptr<Student>>& students) {

    // display the number of students (undergrad or grad)
    std::cout << "Number of students = " << students.size() << std::endl;

    // compute the mean of the total score.
    double mean = 0.0;
    for (auto itr = students.begin(); itr != students.end(); ++itr) {
        mean += (*itr) -> getTotal();
    }
    mean = mean / students.size();
    std::cout << "The mean of the total score = " << mean << std::endl;

    std::cout << "The sorted list of students (id, name, total, grade) in " <<
            "descending order of total:" << std::endl;
    // sort the students based on their total.
    auto sortRuleLambda = [] (const std::shared_ptr<Student>& s1,
                              const std::shared_ptr<Student>& s2) -> bool {
            return s1 -> getTotal() > s2 -> getTotal();
    };
    std::sort(students.begin(), students.end(), sortRuleLambda);

    // print sorted students
    for (auto student : students) {
        std::cout << student -> getId() << ", "
                  << student -> getName() << ", "
                  << student -> getTotal() << ", "
                  << student -> getGrade() << std::endl;
    }
    std:: cout << std::endl;
}