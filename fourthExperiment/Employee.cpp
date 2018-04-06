#include <iostream>
#include <string>
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

        int fullYearsTo(Date &date);
        int daysTo(Date &date);
    private:
        int year;
        int month;
        int day;
        char separator;
        static int DAYS_PER_MONTH[12];
        int checkDay(int day);
        bool isLeapyear(int year);
};

int Date:: DAYS_PER_MONTH[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int year_2, int month_2, int day_2) {
    year = year_2;
    month = month_2;
    day = day_2;
    separator = '-';
}

bool Date::isLeapyear(int year) {
     if( ( year % 4 == 0 && year % 100 != 0 ) ||year % 400 == 0) {
        return true;
    }
    else {
        return false;
    }
}
int Date::checkDay(int day) {
    if (isLeapyear(year)){
        DAYS_PER_MONTH[1] = 29;
    }
    day = day > DAYS_PER_MONTH[month - 1] ? 1 : day;
    return day;
}



void Date::setDate(int year_2, int month_2, int day_2) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    year = year_2;
    month = month_2 > 12 ? 1 : month_2;
    day = day_2 > days[ month_2 ] ? 1 : day;
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
    cout << day;
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
    cout << day;
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

int Date::fullYearsTo(Date &date) {
    if(day_of_year(year, month, day) <= day_of_year(date.year, date.month, date.day) ) {
        return date.year - year;
    }
    else {
        return date.year - year - 1;
    }
}

int Date::daysTo(Date &date) {
    int sum = 0;
    if(date.year > year) {
        if(isLeapyear(year)) {
            sum = sum + (366 -  day_of_year(year, month, day) );
        }
        else {
            sum = sum + (365 - day_of_year(year, month, day) );
        }
        for(int i = year + 1; i < date.year; i++) {
            if(isLeapyear(i)) {
                sum = sum + 366;
            }
            else {
                sum = sum + 365;
            }
        }
        sum = sum + day_of_year(date.year, date.month, date.day);
        return sum;
    }
    if(date.year < year) {
        if(isLeapyear(date.year)) {
            sum = sum + (366 - day_of_year(date.year, date.month, date.day));
        }
        else {
            sum = sum + (365 - day_of_year(date.year, date.month, date.day));
        }
        for(int i = date.year + 1; i < year; i++) {
            if(isLeapyear(i)){
                sum = sum + 366;
            }
            else {
                sum = sum + 365;
            }
        }
        sum = sum + day_of_year(year, month, day);

        return -sum;
    }
    if(date.year == year) {
        if(day_of_year(year, month, day) > day_of_year(date.year, date.month, date.day)) {
            return -(day_of_year(year,month,day)-day_of_year(date.year,date.month,date.day));
        }
        else{
            return day_of_year(date.year, date.month, date.day) - day_of_year(year, month, day);
        }
    }
}

class Employee{
    public:
        Employee(string, string, Date &, Date &);
        void print();
        int getAge(Date &date);
        int getYearsWorked(Date &date);
        int getDaysWorked(Date &date);
        ~Employee(){};
    private:
        string firstName;
        string lastName;
        Date birthDate;
        Date hireDate;
};

Employee::Employee(string first, string last, Date &birth, Date &hire){
    firstName = first;
    lastName = last;
    birthDate = birth;
    hireDate = hire;
}

void Employee::print(){
    cout << firstName << ", " << lastName << " Hired ";
    hireDate.printFullYear();
    cout << " Birthday: ";
    birthDate.printFullYear();
}

int Employee::getAge(Date &date){
    return birthDate.fullYearsTo(date);
}

int Employee::getYearsWorked(Date &date){
    return hireDate.fullYearsTo(date);
}

int Employee::getDaysWorked(Date &date){
    return hireDate.daysTo(date);
}

int main() {
    Date birth(1969, 8, 11);
    Date hire(1998, 4, 1);
    Date today(2010, 4, 30);
    Employee manager("Bob", "Blue", birth, hire);
    cout << endl;
    manager.print();
    cout << endl;
    cout << manager.getAge(today) << endl;
    cout << manager.getDaysWorked(today) << endl;
    return 0;
}
