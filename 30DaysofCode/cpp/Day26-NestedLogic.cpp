#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Date{
    public:
        int day;
        int month;
        int year;
    public:
        Date(int day, int month, int year){
            this->day   = day;
            this->month = month;
            this->year  = year;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int day, month, year, fine;
    cin >> day >> month >> year;
    Date* returned_date = new Date(day,month,year);
    cin >> day >> month >> year;
    Date* due_date = new Date(day,month,year);
    // If the book is returned on or before the expected return date, no fine will be charged (fine=0)
    if(returned_date->year < due_date->year){
        fine = 0;
    }else if(returned_date->year == due_date->year){
        if (returned_date->month <= due_date->month) {
            if(returned_date->day > due_date->day){
                // If the book is returned after the expected return day but still within the same calendar month and year as the expected return date (fine=15*(the number of days late))
                fine = 15 * (returned_date->day-due_date->day);
            }else{
                fine = 0;
            }
        }else if(returned_date->month > due_date->month){
            // If the book is returned after the expected return month but still within the same calendar year as the expected return date, the (fine=500*(the number of months late))
            fine = 500 * (returned_date->month-due_date->month);
        }else{
            fine = 0;
        }
    }else{
        // If the book is returned after the calendar year in which it was expected, there is a fixed fine of (fine=10000)
        fine = 10000;
    }
    cout << fine << endl;
    return 0;
}
