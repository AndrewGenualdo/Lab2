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
#include "header.h"


/*     Pre: loadData, computeAverage (student variant)
 *    Post: data will be populated with the grade for each student
 * Purpose: Assign a grade to each student based on their average grade
 *************************************************************************************************/
void assignGrade(Student data[MAX][SECTIONS], const int size[SECTIONS])
{
    for (int i = 0; i < SECTIONS; i++)
    {
        int students = size[i];
        for (int j = 0; j < students; j++)
        {
            data[j][i].mLetterGrade = gradeToLetter(data[j][i].mAverageGrade);
        }
    }
}

/*     Pre: loadData
 *    Post: data will be populated with the average grade for each student
 * Purpose: Calculate the average grade of each student with different weights for different assignment types
 *
 *    Note: this is the "student variant"
 *************************************************************************************************/
void computeAverage(Student data[][SECTIONS], const int size[SECTIONS])
{

    for (int i = 0; i < SECTIONS; i++)
    {
        int students = size[i];
        for (int j = 0; j < students; j++)
        {
            float grade = 0.0;
            grade += data[j][i].mLabGrade * LAB_PERCENT;
            grade += data[j][i].mPasGrade * PAS_PERCENT;
            grade += data[j][i].mQuizGrade * QUIZ_PERCENT;
            grade += data[j][i].mMidtermGrade * MIDTERM_PERCENT;
            grade += data[j][i].mFinalGrade * FINAL_PERCENT;
            data[j][i].mAverageGrade = grade;
        }
    }
}

/*     Pre: loadData, computeAverage (student variant)
 *    Post: averages will be populated with the average grade of all students in the section
 * Purpose: Compute the average grade of each section
 *
 *    Note: This is the "section variant"
 *************************************************************************************************/
void computeAverage(const Student data[][SECTIONS], const int size[SECTIONS],
                    double averages[SECTIONS])
{
    for (int i = 0; i < SECTIONS; i++)
    {
        int students = size[i];
        float grade = 0.0;
        for (int j = 0; j < students; j++)
        {
            grade+=data[j][i].mAverageGrade;
        }
        averages[i] = grade / (float) students;
    }
}

/*     Pre: loadData, computeAverage (student variant)
 *    Post: grade will be populated with the amount of students in each letter grade
 * Purpose: Count the amount of students for each section in all letter grades
 *
 *    Note: I have no idea what 'grade' is supposed to be so its values are 0-4 (0 = A, 1 = B, 2 = C, 3 = D, 4 = F)
 *
 *  Note 2: I'm not sure if things like A and A- are supposed to be counted separately because it doesn't say anywhere
 *          but (as far as I know) "letter grade" usually refers to only the letter and not any plus or minus following
 *          it, but it can vary from place to place.
 *************************************************************************************************/
void counteGrade(const Student data[][SECTIONS], const int size[SECTIONS],
                 int grade[GRADE][SECTIONS])
{
    for (int i = 0; i < SECTIONS; i++)
    {
        //F is last letter, this resets the count of each letter grade to account for garbage or running it multiple times.
        for(int j=0;j<=LETTER_F;j++) {
            grade[j][i] = 0;
        }
        int students = size[i];
        for (int j = 0; j < students; j++)
        {
            grade[gradeToLetterType(data[j][i].mAverageGrade)][i]++;
        }
    }
}

/*     Pre: loadData, computeAverage (student variants), and assignGrade (in that order)
 *    Post: None
 * Purpose: Display the data of all individual students
 *    Note: The specification just says "the information" and doesn't say what it is,
 *          so I chose these to not send a ton of info to the console.
 *************************************************************************************************/
//Side note:
void displayData(const Student data[][SECTIONS], const int size[SECTIONS])
{
    cout << "[ID] / [Name] / [Letter Grade] / [Average]" << endl;
    for(int i=0;i<SECTIONS;i++) {
        cout << "Section: " << (i+1) << endl;
        int students = size[i];
        for(int j=0;j<students;j++) {
            cout << " [" << data[j][i].mID << "] / [" << data[j][i].mName << "] / [" << data[j][i].mLetterGrade << "] / [" << data[j][i].mAverageGrade << "]" << endl;
        }
    }
}

/*     Pre: loadData, computeAverage (both variants), assignGrade, and counteGrade (in that order)
 *    Post: None
 * Purpose: To display stats for all sections of students
 *************************************************************************************************/
void displayStat(const Student data[][SECTIONS], const int size[SECTIONS],
                 const double averages[SECTIONS], const int grade[GRADE][SECTIONS])
{
    for(int i=0;i<SECTIONS;i++) {
        int students = size[i];
        cout << "Section " << (i+1) << endl;
        cout << " Students: " << students << endl;
        cout << " Class Average: " << averages[i] << endl;
        cout << " Highest Score: " << data[students-1][i].mAverageGrade << endl;
        cout << " Lowest Score: " << data[0][i].mAverageGrade << endl;
        cout << " Letter Distributions:" << endl;
        cout << "  A: " << grade[LETTER_A][i] << endl;
        cout << "  B: " << grade[LETTER_B][i] << endl;
        cout << "  C: " << grade[LETTER_C][i] << endl;
        cout << "  D: " << grade[LETTER_D][i] << endl;
        cout << "  F: " << grade[LETTER_F][i] << endl;
    }
}

/*     Pre: None
 *    Post: None
 * Purpose: return the letter grade ID for the input average grade
 *************************************************************************************************/
int gradeToLetterType(float grade) {
    if(grade >= GRADE_A_MINUS)
        return LETTER_A;
    else if(grade >= GRADE_B_MINUS)
        return LETTER_B;
    else if(grade >= GRADE_C_MINUS)
        return LETTER_C;
    else if(grade >= GRADE_D_MINUS)
        return LETTER_D;
    else
        return LETTER_F;
}

/*     Pre: None
 *    Post: None
 * Purpose: returns the letter grade for the input average grade
 *************************************************************************************************/
string gradeToLetter(float grade)
{
    //I tried like 5 ways of doing this but this is by far the most readable and easiest way to do it even if it seems unnecessary.
    if(grade >= GRADE_A)
        return "A";
    else if(grade >= GRADE_A_MINUS)
        return "A-";
    else if(grade >= GRADE_B_PLUS)
        return "B+";
    else if(grade >= GRADE_B)
        return "B";
    else if(grade >= GRADE_B_MINUS)
        return "B-";
    else if(grade >= GRADE_C_PLUS)
        return "C+";
    else if(grade >= GRADE_C)
        return "C";
    else if(grade >= GRADE_C_MINUS)
        return "C-";
    else if(grade >= GRADE_D_PLUS)
        return "D+";
    else if(grade >= GRADE_D)
        return "D";
    else if(grade >= GRADE_D_MINUS)
        return "D-";
    else
        return "F";
}

/*     Pre: None
 *    Post: data will be populated with student grade information and size will be populated with section sizes
 * Purpose: To load student grades from a saved file
 *************************************************************************************************/
void loadData(Student data[][SECTIONS], int size[SECTIONS])
{
    ifstream studentStream(FILENAME);
    if (studentStream.is_open())
    {
        int section = 0;
        int student = 0;
        while(!studentStream.eof() && student < MAX && section < SECTIONS) {
            studentStream >> data[student][section].mID;
            if(data[student][section].mID == NEXT_SECTION) {
                size[section] = student;
                section++;
                student = 0;
                studentStream >> data[student][section].mID;
            }
            string name;
            studentStream >> name;
            if(name.empty()) {
                break;
            }
            name+=" ";
            data[student][section].mName = name;
            studentStream >> name;
            data[student][section].mName += name;
            studentStream >> data[student][section].mLabGrade;
            studentStream >> data[student][section].mPasGrade;
            studentStream >> data[student][section].mQuizGrade;
            studentStream >> data[student][section].mMidtermGrade;
            studentStream >> data[student][section].mFinalGrade;
            student++;
        }
        size[section] = student;
    }
}

/*     Pre: loadData and computeAverage (student variant)
 *    Post: data will be re-ordered for each student's average grade from lowest to highest.
 * Purpose: To sort the students by grade.
 *************************************************************************************************/
void sortData(Student data[][SECTIONS], const int size[SECTIONS])
{
    for(int i=0;i<SECTIONS;i++) {
        int students = size[i];
        for(int j=0;j<students;j++) {
            for(int k=j+1;k<students;k++) {
                if(data[k][i].mAverageGrade < data[j][i].mAverageGrade) {
                    Student temp = data[j][i];
                    data[j][i] = data[k][i];
                    data[k][i] = temp;
                }
            }
        }
    }
}
