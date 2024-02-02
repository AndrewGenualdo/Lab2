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

struct Student {
    string mID,
           mName,
           letterGrade;
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
const double averages[SECTIONS], const int grade[GRADE]
[SECTIONS]);
void loadData(Student data[][SECTIONS], int size[SECTIONS]);
void sortData(Student data[][SECTIONS], const int size[SECTIONS]);
#endif
