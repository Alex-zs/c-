#include <iostream>
using namespace std;

class Date{
    public:
        Date(int year_2 = 1990, int month_2 = 1, int day_2 = 1);
        void setDate(int year_2, int month_2, int day_2);
        void setYear(int year_2);
        int getYear();
        void setMonth(int month_2);
        int getMonth();
        void setDay(int day_2);
        int getDay();
        void setSeparator(char separator_2);

        void printFullYear();
        void printStandardYear();

        int fullYearsTo(int year_2, int month_2, int day_2);
        int daysTo(int year_2, int month_2, int day_2);
    private:
        int year;
        int month;
        int day;
        char separator;
};

Date::Date(int year_2, int month_2, int day_2) {
    year = year_2;
    month = month_2;
    day = day_2;
    separator = '-';
}

void Date::setDate(int year_2, int month_2, int day_2) {
    year = year_2;
    month = month_2;
    day = day_2;
}

void Date::setYear(int year_2) {
    year = year_2;
}

int Date::getYear() {
    return year;
}

void Date::setMonth(int month_2) {
    month = month_2;
}

int Date::getMonth() {
    return month;
}

void Date::setDay(int day_2) {
    day = day_2;
}

int Date::getDay() {
    return day;
}

void Date:: setSeparator(char separator_2) {
    separator = separator_2;
}

void Date:: printFullYear() {
    cout << year << separator;
    if(month < 10) {
        cout <<"0" ;
    }
    cout << month << separator;
    if(day < 10) {
        cout <<"0";
    }
    cout << day << endl;
}

void Date:: printStandardYear() {
    if(year%100 < 10) {
        cout << "0";
    }
    cout << year%100 << separator;
    if(month < 10) {
        cout << "0";
    }
    cout << month << separator;
    if(day < 10) {
        cout << "0";
    }
    cout << day << endl;
}

int day_of_year(int year,int month, int day) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( (year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 ) {
        days[1] = 29;
    }
    int sum = 0;
    for( int i = 0; i < month - 1; i++) {
        sum = sum + days[i];
    }
    sum = day + sum;

    return sum;
}

int Date::fullYearsTo(int year_2, int month_2, int day_2) {
    if(day_of_year(year, month, day) <= day_of_year(year_2, month_2, day_2) ) {
        return year_2 - year;
    }
    else {
        return year_2 - year - 1;
    }
}
bool is_leap_year(int year) {
    if( ( year % 4 == 0 && year % 100 != 0 ) ||year % 400 == 0) {
        return true;
    }
    else {
        return false;
    }
}

int Date::daysTo(int year_2, int month_2, int day_2) {
    int sum = 0;
    if(year_2 > year) {
        if(is_leap_year(year)) {
            sum = sum + (366 -  day_of_year(year, month, day) );
        }
        else {
            sum = sum + (365 - day_of_year(year, month, day) );
        }
        for(int i = year + 1; i < year_2; i++) {
            if(is_leap_year(i)) {
                sum = sum + 366;
            }
            else {
                sum = sum + 365;
            }
        }
        sum = sum + day_of_year(year_2, month_2, day_2);
        return sum;
    }
    if(year_2 < year) {
        if(is_leap_year(year_2)) {
            sum = sum + (366 - day_of_year(year_2, month_2, day_2));
        }
        else {
            sum = sum + (365 - day_of_year(year_2, month_2, day_2));
        }
        for(int i = year_2 + 1; i < year; i++) {
            if(is_leap_year(i)){
                sum = sum + 366;
            }
            else {
                sum = sum + 365;
            }
        }
        sum = sum + day_of_year(year, month, day);

        return -sum;
    }
    if(year_2 == year) {
        if(day_of_year(year, month, day) > day_of_year(year_2, month_2, day_2)) {
            return -(day_of_year(year,month,day)-day_of_year(year_2,month_2,day_2));
        }
        else{
            return day_of_year(year_2, month_2, day_2) - day_of_year(year, month, day);
        }
    }
}





int main() {
    Date birthDay(1969, 8, 11);
    birthDay.printFullYear();
    birthDay.printStandardYear();
    birthDay.setSeparator('/');
    birthDay.printFullYear();
    birthDay.printStandardYear();
    cout << birthDay.fullYearsTo(2010, 4, 15) << endl;
    cout << birthDay.daysTo(2010, 4, 15) << endl;
    cout << birthDay.daysTo(1949, 10, 1) << endl;

    return 0;
}


