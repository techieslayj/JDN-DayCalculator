# JDN-DayCalculator
This C++ program is a day calculator for any two days in history a user wants to compare. I will also give the Julian Day Number to the user as well.

The first part of this program takes in a date and determines the Julian Day Number for this day in history
* this number is then converted back to its' corresponding Gregorian Calendar date which honestly doesn't have much reason
* to know specifically for this program, however knowing the JDN (Julian Day Number) for a given date can be used to find out
* the Julian Date and/or date if you didn't have knowledge of the date before hand

As previously stated my program will convert the Julian Day Number back to a Gregorian Calendar date which for these purposes I 
choose not to display this part of the program because you have already supplied it with the Gregorian date therefore it would just
restate what you entered into the program

The second part of this program takes in a second date and determines the Julian Day Number for this day in history similar
to the first part. However this date is important because it will be used with the first input date to calculate the amount of
days that have passed between these two dates in history. 

This program makes use of the Julian Day Number calculator formulas from https://en.wikipedia.org/wiki/Julian_day as well as the
Fleigel-Van Flandern algorithm which converts the Julian Day Number to gregorian date.
* This is important because I then construct the program to take these year month and day to calculate the difference in days
* Our final answer is constructed using the Rate Die formula which essential shifts February to the end of the year to account
* for the different days of each month as well as leap years (also used if loops to take account for the years I used)
* Also tells user the amount of hours, minutes, and seconds between 2 dates.

This program was primarily constructed as a practice project to test my skills within C++
I welcome any critique or optimization that could be made to improve my program. 
