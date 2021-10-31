#include <bits/stdc++.h>
using namespace std;

//Delcaration of date class
class Date
{

public:
    //function to check that given year is leap year or not
    int check_leap_year(int year)
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) // if year is a leap year
            return 1;

        else
            return 0;
    }

    //function to calculate number of days in month
    int no_of_days_in_month(int month, int year)
    {
        // jan, march, may, july, aug, oct, dec contains 31 days
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            return 31;

        // april, jun, sept, nov contains 30 days
        if (month == 4 || month == 6 || month == 9 || month == 11)
            return 30;

        if (month == 2)
        {
            int n = check_leap_year(year);
            if (n == 1) // if year is a leap year then Feb will contain 29 days, otherwise it contains 28 days
                return 29;

            else
                return 28;
        }
        return 0;
    }

    //function to calculate difference of days
    long long int difference_of_days(int day1, int month1, int year1, int day2, int month2, int year2)
    {
        if (year1 == year2) // for same years.
        {
            if (month1 == month2) // for exactly same month and year.
            {
                if (day1 == day2) // for exactly same dates
                    return 0;
                else              // for same year, same month but diff days
                    return abs(day1 - day2); 
            }
            else if (month1 < month2) // for same year, but month 2 is greater than month 1.
            {
                int result = 0;
                for (int i = month1; i < month2; i++)
                    result = result + no_of_days_in_month(i, year1);

                if (day1 == day2) // for same year, same day but diff month
                    return result;
                else if (day1 < day2) // for same year, diff month and day 2 is greater than day 1.
                {
                    result = result + (day2 - day1);
                    return result;
                }
                else // for same year, diff month and day 1 is greater than day 2.
                {
                    result = result - (day1 - day2);
                    return result;
                }
            }
            else // for same year, but month 1 is greater than month 2.
            {
                int result = 0;
                for (int i = month2; i < month1; i++) 
                    result = result + no_of_days_in_month(i, year1);

                if (day1 == day2) // for same year and days, but months are diff.
                    return result;
                else if (day2 < day1) // for day 2 is greater than day 1, months are diff and same years.
                {
                    result = result + (day1 - day2);
                    return result;
                }
                else // for day 1 is greater than day 2, months are diff and same years.
                {
                    result = result - (day2 - day1);
                    return result;
                }
            }
        }
        else if (year1 < year2) // if "year 2" is greater than "year 1"
        {
            int temp = 0;
            for (int i = year1; i < year2; i++)
            {
                if (check_leap_year(i)) // checking if it is a leap year.
                    temp = temp + 366;
                else
                    temp = temp + 365;
            }

            if (month1 == month2) // checking if the months are same.
            {
                if (day1 == day2) // for same month, same day but diff year
                    return temp;
                else if (day1 < day2) // for same month, but diff year and day 2 is greater than day 1.
                    return temp + (day2 - day1);
                else // for same month, but diff year and day 1 is greater than day 2.
                    return temp - (day1 - day2);
            }
            else if (month1 < month2) // if the month 2 is greater than month 1.
            {
                int result = 0;
                for (int i = month1; i < month2; i++)
                    result = result + no_of_days_in_month(i, year2); 

                if (day1 == day2) // for same day, diff year and  month
                    return temp + result;
                else if (day1 < day2) // for day 2 is greater than day 1, diff year and  month
                {
                    result = result + (day2 - day1);
                    return temp + result;
                }
                else // for day 1 is greater than day 2, diff year and  month
                {
                    result = result - (day1 - day2);
                    return temp + result;
                }
            }
            else // if the month 1 is greater than month 2.
            {
                int result = 0;
                for (int i = month2; i < month1; i++)
                    result = result + no_of_days_in_month(i, year2);

                if (day1 == day2) // for same day, diff year and  month
                    return temp - result;
                else if (day2 < day1) // for day 1 is greater than day 2, diff year and  month
                {
                    result = result + (day1 - day2);
                    return temp - result;
                } 
                else // for day 2 is greater than day 1, diff year and  month
                {
                    result = result - (day2 - day1);
                    return temp - result;
                }
            }
        }
        // if "year 1" is greater than "year 2"
        else 
        {
            int temp = 0; 
            for (int i = year2; i < year1; i++)
            {
                if (check_leap_year(i)) // checking if any of the year is leap year.
                    temp = temp + 366;
                else
                    temp = temp + 365;
            }

            if (month1 == month2) // for same month but diff year.
            {
                if (day1 == day2) // for same day, same month but diff year. 
                    return temp;
                else if (day2 < day1) // for the day 1 is greater than day 2, but same month and diff year.
                    return temp + (day1 - day2);
                else // for the day 2 is greater than day 1, but same month and diff year.
                    return temp - (day2 - day1);
            }
            else if (month2 < month1) // for month 1 is greater than month 2 and year is diff.
            {
                int result = 0;
                for (int i = month2; i < month1; i++)
                    result = result + no_of_days_in_month(i, year1);

                if (day1 == day2) // for days are same but month and year are diff.
                    return temp + result;
                else if (day2 < day1) // for day 2 is greater than day 1, month and year are diff.
                {
                    result = result + (day1 - day2);
                    return temp + result;
                }
                else// for day 1 is greater than day 2, month and year are diff.
                {
                    result = result - (day2 - day1);
                    return temp + result;
                }
            }
            else // for month 2 is greater than month 1 and year is diff.
            {
                int result = 0;
                for (int i = month1; i < month2; i++) 
                    result = result + no_of_days_in_month(i, year1);

                if (day1 == day2) // for same day, diff year and diff month
                    return temp - result;
                else if (day1 < day2) // for diff year, month and day 2 is greater than day 1.
                {
                    result = result + (day2 - day1);
                    return temp - result;
                }
                else // for diff year, month and day 1 is greater than day 2.
                {
                    result = result - (day1 - day2);
                    return temp - result;
                }
            }
        }
    }
};