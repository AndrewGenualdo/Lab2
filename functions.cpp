//
// Created by andrew.genualdo on 2/6/2024.
//
#include "header.h"

void assignGrade(Student data[MAX][SECTIONS], const int size[SECTIONS])
{
    for (int i = 0; i < SECTIONS; i++)
    {
        int students = size[i];
        for (int j = 0; j < students; j++)
        {
            data[i][j].letterGrade = letterGrade(data[i][j].mAverageGrade);
        }
    }
}

void computeAverage(Student data[][SECTIONS], const int size[SECTIONS])
{
    float grade = 0.0;
    for (int i = 0; i < SECTIONS; i++)
    {
        int students = size[i];
        for (int j = 0; j < students; j++)
        {
            grade += data[i][j].mLabGrade * LAB_PERCENT;
            grade += data[i][j].mPasGrade * PAS_PERCENT;
            grade += data[i][j].mQuizGrade * QUIZ_PERCENT;
            grade += data[i][j].mMidtermGrade * MIDTERM_PERCENT;
            grade += data[i][j].mFinalGrade * FINAL_PERCENT;
        }
    }
}

void computeAverage(const Student data[][SECTIONS], const int size[SECTIONS],
                    double averages[SECTIONS])
{

}

void counteGrade(const Student data[][SECTIONS], const int size[SECTIONS],
                 int grade[GRADE][SECTIONS])
{

}

void displayData(const Student data[][SECTIONS], const int size[SECTIONS])
{

}

void displayStat(const Student data[][SECTIONS], const int size[SECTIONS],
                 const double averages[SECTIONS], const int grade[GRADE]
[SECTIONS])
{

}

void loadData(Student data[][SECTIONS], int size[SECTIONS])
{
    ifstream studentStream(FILENAME);
    if(studentStream.is_open()) {
        int lineType = 0;
        int section = 0;
        string line;
        while(getline(studentStream, line)) {
            if(line == "*****") {
                section++;
            } else {
                if(lineType == 0) //ID

                lineType++;
            }

        }
    }
}

void sortData(Student data[][SECTIONS], const int size[SECTIONS])
{

}

string letterGrade(float grade)
{
    int input = (int) grade;
    string suffix;
    if (input % 10 >= 0 && input % 10 < 93)
    {
        suffix = "-";
    } else if (input % 10 >= 87 && input <= 9)
    {
        suffix = "+";
    } else
    {
        suffix = "";
    }

    if (input == 100)
    {
        return "A+";
    } else
    {
        return LETTERS[-(input / 10)] + suffix;
    }
}
