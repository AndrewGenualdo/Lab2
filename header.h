/*
 * Author: Andrew Genualdo
 * Class: CSI-240-04
 * Assignment: Lab 2
 * Date Assigned: Unknown
 * Due Date: Feb 9, 2024 @ 1pm
 *
 * Description:
 * A system to sort and calculate different values in relation to a group of students grades.
 *
 * Certification of Authenticity:
 * I certify that this is entirely my own work, except where I have given
 * fully-documented references to the work of others. I understand the definition and
 * consequences of plagiarism and acknowledge that the assessor of this assignment
 * may, for the purpose of the assessing this assignment:
 * - Reproduce this assignment and provide a copy to another member of academic staff;
 * and/or
 * - Communicate a copy of this assignment to a plagiarism checking service (which may
 * then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
 */

#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
const int MAX = 20, SECTIONS = 2, GRADE = 12;
const string FILENAME = "students.txt";
const string NEXT_SECTION = "*****";

const int LETTER_A = 0;
const int LETTER_B = 1;
const int LETTER_C = 2;
const int LETTER_D = 3;
const int LETTER_F = 4;

const int GRADE_A = 93;
const int GRADE_A_MINUS = 90;
const int GRADE_B_PLUS = 87;
const int GRADE_B = 83;
const int GRADE_B_MINUS = 80;
const int GRADE_C_PLUS = 77;
const int GRADE_C = 73;
const int GRADE_C_MINUS = 70;
const int GRADE_D_PLUS = 67;
const int GRADE_D = 63;
const int GRADE_D_MINUS = 60;

const float LAB_PERCENT = 0.15;
const float PAS_PERCENT = 0.35;
const float QUIZ_PERCENT = 0.1;
const float MIDTERM_PERCENT = 0.15;
const float FINAL_PERCENT = 0.25;

//Not sure if this is supposed to be declared here, but it doesn't say where to put it in the student handbook.
struct Student
{
    string mID,
            mName,
            mLetterGrade;
    float mLabGrade,
            mPasGrade,
            mQuizGrade,
            mMidtermGrade,
            mFinalGrade,
            mAverageGrade;
};

void assignGrade(Student data[][SECTIONS], const int size[SECTIONS]);

void computeAverage(Student data[][SECTIONS], const int size[SECTIONS]);

void computeAverage(const Student data[][SECTIONS], const int size[SECTIONS],
                    double averages[SECTIONS]);

void counteGrade(const Student data[][SECTIONS], const int size[SECTIONS],
                 int grade[GRADE][SECTIONS]);

void displayData(const Student data[][SECTIONS], const int size[SECTIONS]);

void displayStat(const Student data[][SECTIONS], const int size[SECTIONS],
                 const double averages[SECTIONS], const int grade[GRADE][SECTIONS]);

string gradeToLetter(float grade);

int gradeToLetterType(float grade);

void loadData(Student data[][SECTIONS], int size[SECTIONS]);

void sortData(Student data[][SECTIONS], const int size[SECTIONS]);

#endif
