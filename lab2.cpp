//No header here since I didn't write this

#include "header.h"

int main()
{
   Student data[MAX][SECTIONS];
   int     size[SECTIONS];
   double  averages[SECTIONS];
   int     letterGrade[GRADE][SECTIONS];

   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(1);

   loadData(data, size);
   computeAverage(data, size);
   assignGrade(data, size);
   sortData(data, size);
   displayData(data, size);
   computeAverage(data, size, averages);
   counteGrade(data, size, letterGrade);
   displayStat(data, size, averages, letterGrade);

   return 0;
}