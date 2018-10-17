#include <iostream>
#include <string>
using namespace std;

template <typename T>
T compare(T* array, int n){
    T max = array[0];
    for(int i = 0; i < n; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

class Date{
public:
    Date(int year_2 = 1990, int month_2 = 1, int day_2 = 1);
    int operator - ( Date &date2);
    bool operator > (Date &date2);
    bool operator < (Date &date2);
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

    int fullYearsTo(Date &date2);
    int daysTo(int year_2, int month_2, int day_2);
    int day_of_year();
private:
    int year;
    int month;
    int day;
    char separator;
};
int Date::day_of_year() {
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
int day_of_year(int year, int month, int day) {
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

bool Date::operator > (Date &date2){
    int year_2, month_2, day_2;
    year_2 = date2.getYear();
    month_2 = date2.getMonth();
    day_2 = getDay();
    if(year > year_2) return true;
    if(year < year_2) return false;
    if(year == year_2){
        if(this->day_of_year() > date2.day_of_year()) {
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}

bool Date::operator < (Date &date2){
    int year_2, month_2, day_2;
    year_2 = date2.getYear();
    month_2 = date2.getMonth();
    day_2 = getDay();
    if(year > year_2) return false;
    if(year < year_2) return true;
    if(year == year_2){
        if(this->day_of_year() > date2.day_of_year()) {
            return false;
        }
        else{
            return true;
        }
    }
    return false;
}

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

int Date::fullYearsTo(Date &date2) {
  int year_2, month_2, day_2;
  year_2 = date2.getYear();
  month_2 = date2.getMonth();
  day_2 = getDay();

    if(::day_of_year(year, month, day) <= ::day_of_year(year_2, month_2, day_2) ) {
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

int Date::operator-(Date &date2){
    int year_2, month_2, day_2;
    year_2 = date2.getYear();
    month_2 = date2.getMonth();
    day_2 = getDay();

    int sum = 0;
    if(year_2 > year) {
        if(is_leap_year(year)) {
            sum = sum + (366 -  ::day_of_year(year, month, day) );
        }
        else {
            sum = sum + (365 - ::day_of_year(year, month, day) );
        }
        for(int i = year + 1; i < year_2; i++) {
            if(is_leap_year(i)) {
                sum = sum + 366;
            }
            else {
                sum = sum + 365;
            }
        }
        sum = sum + ::day_of_year(year_2, month_2, day_2);
        return -sum;
    }
    if(year_2 < year) {
        if(is_leap_year(year_2)) {
            sum = sum + (366 - ::day_of_year(year_2, month_2, day_2));
        }
        else {
            sum = sum + (365 - ::day_of_year(year_2, month_2, day_2));
        }
        for(int i = year_2 + 1; i < year; i++) {
            if(is_leap_year(i)){
                sum = sum + 366;
            }
            else {
                sum = sum + 365;
            }
        }
        sum = sum + ::day_of_year(year, month, day);

        return sum;
    }
    if(year_2 == year) {
        if(::day_of_year(year, month, day) > ::day_of_year(year_2, month_2, day_2)) {
            return -(::day_of_year(year,month,day)-::day_of_year(year_2,month_2,day_2));
        }
        else{
            return -(::day_of_year(year_2, month_2, day_2) - ::day_of_year(year, month, day));
        }
    }

    return 0;
}


int main(){
    Date dates[3] = {
        Date(1999,2,20),
        Date(2010,1,29),
        Date(2009,9,9),
    };

    Date max = compare(dates, 3);
    max.printFullYear();
    return 0;
}
