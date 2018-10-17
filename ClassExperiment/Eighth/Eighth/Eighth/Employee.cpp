#include <iostream>
#include <string>
using namespace std;

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

class Employee{
    public:
        Employee(string, string, Date &, Date &);
        Employee();
        void print();
        int getAge(Date &date);
        int getYearsWorked(Date &date);
        int getDaysWorked(Date &date);
        static Employee getMostFaith(Employee employees[], int n);
        ~Employee(){};
    private:
        string firstName;
        string lastName;
        Date birthDate;
        Date hireDate;
};

Employee Employee::getMostFaith(Employee employees[], int n){
  Date today(2010, 4, 30);
  Employee max = employees[0];
  for(int i = 1; i < n; i++){
    if(employees[i].getDaysWorked(today) > max.getDaysWorked(today)){
      max = employees[i];
    }
  }
  return max;
}
Employee::Employee(){

}
Employee::Employee(string first, string last, Date &birth, Date &hire){
    firstName = first;
    lastName = last;
    birthDate = birth;
    hireDate = hire;
}

void Employee::print(){
    cout << firstName << ", " << lastName << endl << "Hired ";
    hireDate.printFullYear();
    cout << "Birthday: ";
    birthDate.printFullYear();
}

int Employee::getAge(Date &date){
    return birthDate.fullYearsTo(date);
}

int Employee::getYearsWorked(Date &date){
    return hireDate.fullYearsTo(date);
}

int Employee::getDaysWorked(Date &date){
    return date - hireDate;
}

int main() {
    Date birth(1969, 8, 11);
    Date today(2010, 4, 30);
    Date hire(1998, 4, 1);
    Date hire2(1995, 4, 1);
    Date hire3(1996, 4, 1);
    Date hire4(1999, 4, 1);
    Date hire5(1998, 10, 1);
    Employee manager1("Bob1", "Blue1", birth, hire);
    Employee manager2("Bob2", "Blue2", birth, hire2);
    Employee manager3("Bob3", "Blue3", birth, hire3);
    Employee manager4("Bob4", "Blue4", birth, hire4);
    Employee manager5("Bob5", "Blue5", birth, hire5);
    Employee employees[] = {manager1, manager2, manager3, manager4, manager5};
    Employee max;
    max = Employee::getMostFaith(employees, 5);
    max.print();
    cout << "工作了" <<  max.getDaysWorked(today) << "天" << endl;
    return 0;
}
