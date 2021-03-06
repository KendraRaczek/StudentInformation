///////////////////////////////////////////////////////////////////////////////
// File Name:      Student.hpp
//
// Author:         Gerald, Isaac
// CS email:       gerald@cs.wisc.edu, isung@cs.wisc.edu
//
// Description:    The header file for the Student class.
//
// IMPORTANT NOTE: You should NOT add/modify/remove any PUBLIC methods.
//                 If you need, you may add some PRIVATE methods.
///////////////////////////////////////////////////////////////////////////////

#ifndef A4_STUDENT_HPP
#define A4_STUDENT_HPP

#include <string>
#include <vector>

/**
 * @brief An abstract base class for a Student.
 */
class Student {
private:
    // a student's unique id.
    int id;
    std::string name;
    std::vector<double> assignmentsScore;
    double projectScore;
    static int numStudents;

/*Private methods, if any should be added BELOW this line*/


/*Private methods, if any should be added ABOVE this line*/

public:
    /**
     * @brief A parameterised constructor for a Student.
     *
     * @param name Student's name.
     * @param assignmentsScore Student's assignment scores.
     * @param projectScore Student's project score.
     */
    Student(std::string name,
            std::vector<double> &assignmentsScore,
            double projectScore);

    /**
     * @brief Getter for student's id.
     *
     * @return The id of the student.
     */
    int getId();

    /**
     * @brief Getter for student's name.
     *
     * @return The name of the student.
     */
    std::string getName();

    /**
     * @brief Getter for student's assignment scores.
     *
     * @return A reference to the vector of student's assignment scores.
     */
    std::vector<double>& getAssignmentsScore();

    /**
     * @brief Getter for student's project score.
     *
     * @return The project score of the student.
     */
    double getProjectScore();

    /**
     * @brief Get the total number of students.
     *
     * @return The total number of students.
     */
    static int getNumStudents();

    /**
     * @brief Prints the details of the student.
     *
     * @example This method prints the following details of a student.
     * STUDENT DETAILS:
	 * Id = 2
     * Name = Joe Dart
     * Assignments = [67, 78, 96, 91, 97, 96]
     * Project = 96
     * Total = 90.05
     * Grade = CR
     */
    virtual void printDetails();

    /**
     * @brief Get the total score of a student.
     *
     * @return The total score of the student.
     */
    virtual double getTotal() = 0;

    /**
     * @brief Get the letter grade obtained by a student.
     *
     * @return The letter grade of the student. The possible letter grades are "CR" and "N".
     */
    virtual std::string getGrade() = 0;
};

#endif //A4_STUDENT_HPP
