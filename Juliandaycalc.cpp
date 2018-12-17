//
//  Juliandaycalc.cpp
//  
//
//  Created by AJ Iglesias on 12/14/18.
//

#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;
// Below :
// M = months Y = years D = days MIN = minutes H = hours S = seconds JDN = Julian Day NUmber TOD = Time of Day

int D, M, Y, D2, M2, Y2, year, day, mon, year2, day2, mon2;


int main() {
    
    bool run = true;
    while(run){
    
        cout << "First part of the program will calculate the Julian day for a given date!" << endl;

        // Enter day user wants
        cout << "The day you are looking to use for calculation" << endl;
        cin >> D;

        // Enter the Month user wants
        cout << "The month you are looking to use for calculation" << endl;
        cin >> M;

        // Enter the year user wants
        cout << "The year you are looking to use for calculation" << endl;
        cin >> Y;

        //Julian Day algorithm re: wikipedia.org based on the Gregorian calendar NOT Julian calendar

        int JDN = (1461 * (Y + 4800 + (M - 14)/12))/4 + (367 * (M - 2 - 12 * ((M - 14)/12)))/ 12 - (3 * ((Y + 4900 + (M - 14)/12)/100))/4 + D - 32075;

        cout << "The Julian Day for this day in history is :" << JDN << endl;
        // JDN (Julian Day Number) for a given date in history as long as after 4713 BC

       

        //set of calculations according to the Fleigel van Flandern algorithm for Julian Day Number to Gregorian Date conversion

        int f = JDN + 68569;

            // algorithm and parameters to determine day (D) month (M) and year (Y) for the calculated Julian Day Number
        int e = (4 * f) / 146097;

        int g = f - (146097 * e + 3) / 4;

        int h = 4000 * (g+1) / 1461001;

        int t = g - (1461 * h/4) + 31;

        int u = (80 * t) / 2447;

        int v = u / 11;

            // Determine year, month, and day for corresponding Gregorian calendar date (is the year, month and day user entered in beginning of program

        year = 100 * (e -49) + h + v;

        mon = u + 2 - 12 * v;

        day = t - 2447 * u/80;

            // Now final part of the program compares both Gregorian dates and see how many days have past between dates

            // Enter second day user wants to use for comparison
        cout << "The day you are looking to use for calculation" << endl;
        cin >> D2;

            // Enter the second Month user wants to use for comparison
        cout << "The month you are looking to use for calculation" << endl;
        cin >> M2;

            // Enter the second year user wants to use for comparison
        cout << "The year you are looking to use for calculation" << endl;
        cin >> Y2;

        int JDN2 = (1461 * (Y2 + 4800 + (M2 - 14)/12))/4 + (367 * (M2 - 2 - 12 * ((M2 - 14)/12)))/ 12 - (3 * ((Y2 + 4900 + (M2 - 14)/12)/100))/4 + D2 - 32075;

        cout << "The Julian Day for this day in history is :" << JDN2 << endl;

        int f2 = JDN2 + 68569;

        // algorithm and parameters to determine day (D) month (M) and year (Y) for the calculated Julian Day Number
        int e2 = (4 * f2) / 146097;

        int g2 = f2 - (146097 * e2 + 3) / 4;

        int h2 = 4000 * (g2+1) / 1461001;

        int t2 = g2 - (1461 * h2/4) + 31;

        int u2 = (80 * t2) / 2447;

        int v2 = u2 / 11;

        // Determine year, month, and day for corresponding calendar date

        year2 = 100 * (e2 -49) + h2 + v2;
        // account for leap years
        // _leap is true if it is a leap year

        mon2 = u2 + 2 - 12 * v2;

        day2 = t2 - 2447 * u2/80;

        // To find out how many days have passed between the two events

        // account for leap years to calculate days
        int numleap1;
        int numleap2;

        if(mon > 2){
            numleap1 = year/4 - year/100 + year/400;
        }
        else if(mon <= 2){
            numleap1 = (year-1)/4 - (year-1)/100 + (year-1)/400;
        }

        if(mon2 > 2){
            numleap2 = year2/4 - year2/100 + year2/400;
        }
        else if(mon2 <= 2){
            numleap2 = (year2-1)/4 - (year2-1)/100 + (year2-1)/400;
        }

        //Final solution of days in between second part of the equation is the Rata Die algorithm which essentially shifts February to the end of the year accounts for different amount of days in each month

        int numdays = year * 365 + numleap1 + (153* mon - 457)/5 + day - 306;
        int numdays2 = year2 * 365 + numleap2 + (153* mon2 - 457)/5 + day2 - 306;

        int betdates = abs(numdays2 - numdays);

        cout << "Difference between these two dates is " << betdates << " days" << endl;
    
        
    return 0;
}
}

