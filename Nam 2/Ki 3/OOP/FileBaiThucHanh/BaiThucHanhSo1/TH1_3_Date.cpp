#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Date {
private:
    int nYear;
    int nMonth;
    int nDay;

    bool IsLeapYear(int year) const {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }

    int DaysInMonth(int month, int year) const {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return IsLeapYear(year) ? 29 : 28;
            default:
                return 0; 
        }
    }

    int TotalDays(int year, int month, int day) const {
        int days = 0;
        // Tinh tong so ngay tu nam 0 den ngay (year-1, 12, 31)
        for (int y = 0; y < year; ++y) {
            days += IsLeapYear(y) ? 366 : 365;
        }
        
        // Tinh tong so ngay trong nam hien tai cho den thang (month-1)
        for (int m = 1; m < month; ++m) {
            days += DaysInMonth(m, year);
        }
        // Tinh so ngay trong thang hien tai
        days += day;
        return days;
    }

public:
    void Input() {
        cout << "Insert Date (yy/mm/dd): ";
        cin >> nYear >> nMonth >> nDay;
    }

    void Init(int yy, int mm, int dd) {
        nYear = yy;
        nMonth = mm;
        nDay = dd;
    }

    bool IsValid() const {
        if (nMonth < 1 || nMonth > 12) {
            return false; 
        }
        if (nDay < 1 || nDay > DaysInMonth(nMonth, nYear)) {
            return false; 
        }
        return true;
    }

    void Print() const {
        cout << nYear << "/" << nMonth << "/" << nDay << endl;
    }

    int DaysBetween(const Date& other) const {
        int days1 = TotalDays(nYear, nMonth, nDay);
        int days2 = TotalDays(other.nYear, other.nMonth, other.nDay);
        return abs(days1 - days2);
    }
};

int main() {
    Date date1, date2;

    cout << "Enter first date:" << endl;
    date1.Input();
    if (!date1.IsValid()) {
        cout << "Invalid date." << endl;
        return 1;
    }

    cout << "Enter second date:" << endl;
    date2.Input();
    if (!date2.IsValid()) {
        cout << "Invalid date." << endl;
        return 1;
    }

    int daysBetween = date1.DaysBetween(date2);

    cout << "Days between the two dates: " << daysBetween << endl;

    return 0;
}
