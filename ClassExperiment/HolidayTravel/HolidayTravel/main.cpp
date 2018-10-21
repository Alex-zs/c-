#include <iostream>
#include <string>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <sstream>
#include <iomanip>
using namespace std;
const int MAX_TYPE = 10;
class TicketOffice;
class TravelAgency;
class Team;
//枚举


//类定义
//行李
class Luggage {
public:
    Luggage() {};
    Luggage(int);
    int code;
};

//票
class Ticket {
public:
    Ticket() {};
    Ticket(string where, int luggageNum,string type,char hostName);
    
    string where;
    int money;
    string type;
    char hostName;
};

//游客
class Passenger {
public:
    Passenger() {};
    Passenger(char name, string type, string purpose, int luggageNum, TicketOffice &ticketOffice, TravelAgency &travelAgency);
    void toTravel(char name, string type, string purpose, int luggageNum, TicketOffice &ticketOffice, TravelAgency &travelAgency);
    void buyTicket(TicketOffice &ticketOffice, string where);
    int signTeam(TravelAgency &travelAgency, TicketOffice &ticketOffice, string where);
    
    //char name;
    char name;
    string travelType;
    int luggagesNum;
    Luggage luggages[10];
    Ticket ticket;
    
    
};

//旅行团
class Team {
public:
    Team() {};
    Team(int peopleNum, int allMoney, string where) { this->peopleNum = peopleNum; this->allMoney = allMoney; this->where = where; };
    Ticket signName(Passenger &Passenger, TicketOffice &ticketOffice, string where);
    Passenger passengers[6];
    int peopleNum;
    int allMoney;
    string where;
    
};

//旅行社
class TravelAgency {
public:
    TravelAgency(int peopleNum) { this->peopleNum = peopleNum; };
    int signName(Passenger &Passenger, TicketOffice &ticketOffice, string where);
    void totlaInfo();
    Team teams[5];
    int peopleNum;
    
};

//售票处
class TicketOffice {
public:
    TicketOffice(int ticketsNum) { this->ticketsNum = ticketsNum; };
    Ticket saleTickets(string, int , string type,char name);
    void totalInfo();
private:
    Ticket tickets[66];
    int ticketsNum;
};

//成员函数
Luggage::Luggage(int Code) { this->code = Code; }

Ticket::Ticket(string where, int luggageNum, string type, char hostName) {
    this->where = where;
    this->type = type;
    this->hostName = hostName;
    if (where == "DomesticShort")
        this->money = 10;
    else if (where == "DomesticLong")
        this->money = 100;
    else
        this->money = 500;
    /*else if (luggageNum <= 2)
     this->money = 500;
     else
     this->money = 500 + 100 * (luggageNum - 2);*/
}

void Passenger::buyTicket(TicketOffice &ticketOffice, string where) {
    this->ticket = ticketOffice.saleTickets(where, this->luggagesNum,"free",this->name);
}

Passenger::Passenger(char name, string type, string purpose, int luggageNum, TicketOffice &ticketOffice, TravelAgency &travelAgency) :ticket("None", 0,"None",'0') {
    this->name = name;
    cout << "我是" << this->name << ",";
    
    if (type == "free") {
        cout << "选择自由行,";
        buyTicket(ticketOffice, purpose);
    }
    else {
        cout << "报名旅行社，选择";
        signTeam(travelAgency, ticketOffice, purpose);
    }
    
    if (purpose == "DomesticShort")
        cout << "国内短途";
    else if (purpose == "DomesticLong")
        cout << "国内长途";
    else
        cout << "国际游";
    cout << "携带" << this->luggagesNum << "件行李,行李编号是";
    for (int i = 0; i<this->luggagesNum; i++)
        cout << this->luggages[i].code << ",";
    
    cout << "买票需付" << this->ticket.money << "元" << endl;
}
void Passenger::toTravel(char name, string type, string purpose, int luggageNum, TicketOffice &ticketOffice, TravelAgency &travelAgency) {
    this->name = name;
    this->luggagesNum = luggageNum;
    for (int i = 1; i <= luggageNum; i++) {
        Luggage newLuggage(i);
        this->luggages[i-1] = newLuggage;
    }
    cout << "我是乘客" << this->name << ",";
    
    if (type == "free") {
        cout << "选择自由行,";
        buyTicket(ticketOffice, purpose);
    }
    else {
        cout << "报名旅行社，选择";
    }
    
    if (purpose == "DomesticShort")
        cout << "国内短途,";
    else if (purpose == "DomesticLong")
        cout << "国内长途,";
    else
        cout << "国际游,";
    
    if (type != "free"&&!signTeam(travelAgency, ticketOffice, purpose)) {
        cout << "不去了" << endl;
        return;
    };
    
    if (this->luggagesNum == 0) {
        cout << "不携带行李,";
    }
    else {
        cout << "携带" << this->luggagesNum << "件行李,行李编号是";
        for (int i = 0; i<this->luggagesNum; i++)
            cout << this->name << setw(2) << setfill('0') << this->luggages[i].code << ",";
    }
    
    //
    cout << "买票需付" << this->ticket.money << "元." ;
    if (purpose == "International"&&this->luggagesNum>2) {
        cout << "行李托运费"<<(luggagesNum-2)*100<<"元" ;
    }
    cout << endl;
}


int Passenger::signTeam(TravelAgency &travelAgency, TicketOffice &ticketOffice,string where) {
    return travelAgency.signName(*this, ticketOffice,where);
}





Ticket Team::signName(Passenger &passenger, TicketOffice &ticketOffice, string where) {
    this->peopleNum++;
    Ticket newTicket = ticketOffice.saleTickets(where, passenger.luggagesNum,"team",passenger.name);
    allMoney += newTicket.money;
    return newTicket;
}



void TravelAgency::totlaInfo() {
    cout << "\n\n旅行社开始报名" << endl;
    cout << "旅行社共计安排了5个旅行团，共计" << this->peopleNum << "人报名。" << endl;
    cout << "出行的目的分别是：";
    for (int i = 0; i<5; i++) {
        cout << this->teams[i].where << ",";
    }
    cout << "每个旅行团的人数分别是:";
    for (int i = 0; i<5; i++)
        cout << this->teams[i].peopleNum << ",";
    cout << "每个旅行团需要支付的票价是：";
    for (int i = 0; i<5; i++)
        cout << this->teams[i].allMoney << ",";
    
}
int TravelAgency::signName(Passenger &passenger, TicketOffice &ticketOffice,string where) {
    for (int i = 0; i<5; i++) {
        if (this->teams[i].where == where && this->teams[i].peopleNum<6) {
            Ticket newTicket(where, passenger.luggagesNum,"team",passenger.name);
            passenger.ticket = newTicket;
            this->teams[i].signName(passenger, ticketOffice,where);
            this->peopleNum++;
            return 1;
        }
    }
    cout << "没有合适的旅行团," ;
    return 0;
    
    
}



Ticket TicketOffice::saleTickets(string where, int luggageNum,string type,char name) {
    Ticket newTicket(where, luggageNum,type,name);
    this->tickets[ticketsNum] = newTicket;
    this->ticketsNum++;
    return newTicket;
}

void TicketOffice::totalInfo() {
    int freeNum=0;
    int teamNum=0;
    int DomesticShortFree = 0;
    int DomesticLongFree = 0;
    int InternationalFree = 0;
    int DomesticShortTeam = 0;
    int DomesticLongTeam = 0;
    int InternationalTeam = 0;
    cout << "\n售票处开始售票" << endl;
    
    cout << "售票结束，营业额统计信息如下：" << endl;
    cout << "共售出" <<this->ticketsNum<< "张票" << endl;
    for (int i = 0; i < this->ticketsNum; i++) {
        if (this->tickets[i].type == "free") {
            if (this->tickets[i].where == "DomesticShort")
                DomesticShortFree+= this->tickets[i].money;
            else if (this->tickets[i].where == "DomesticLong")
                DomesticLongFree += this->tickets[i].money;
            else
                InternationalFree += this->tickets[i].money;
        }
        else {
            if (this->tickets[i].where == "DomesticShort")
                DomesticShortTeam += this->tickets[i].money;
            else if (this->tickets[i].where == "DomesticLong")
                DomesticLongTeam += this->tickets[i].money;
            else
                InternationalTeam += this->tickets[i].money;
        }
    }
    
    cout << "\n国内短途旅行:"<< DomesticShortFree << "元,乘客姓名:";
    for (int i = 0; i < this->ticketsNum; i++) {
        if (this->tickets[i].type == "free"&&this->tickets[i].where == "DomesticShort")
            cout <<"乘客"<< this->tickets[i].hostName << ",";
    }
    cout << "\n国内长途自由行:" << DomesticLongFree << "元,乘客姓名:";
    for (int i = 0; i < this->ticketsNum; i++) {
        if (this->tickets[i].type == "free"&&this->tickets[i].where == "DomesticLong")
            cout << "乘客" << this->tickets[i].hostName << ",";
    }
    cout << "\n国际游自由行:" << InternationalFree << "元,乘客姓名:";
    for (int i = 0; i < this->ticketsNum; i++) {
        if (this->tickets[i].type == "free"&&this->tickets[i].where == "International")
            cout << "乘客" << this->tickets[i].hostName << ",";
    }
    cout << "\n国内短途团购:" << DomesticShortTeam << "元,乘客姓名:";
    for (int i = 0; i < this->ticketsNum; i++) {
        if (this->tickets[i].type == "free"&&this->tickets[i].where == "DomesticShort")
            cout << "乘客" << this->tickets[i].hostName << ",";
    }
    cout << "\n国内长途团购:" << DomesticLongTeam << "元,乘客姓名:";
    for (int i = 0; i < this->ticketsNum; i++) {
        if (this->tickets[i].type == "free"&&this->tickets[i].where == "DomesticLong")
            cout << "乘客" << this->tickets[i].hostName << ",";
    }
    cout << "\n国际游团购:" << InternationalTeam << "元,乘客姓名:";
    for (int i = 0; i < this->ticketsNum; i++) {
        if (this->tickets[i].type == "free"&&this->tickets[i].where == "International")
            cout << "乘客" << this->tickets[i].hostName << ",";
    }
    cout << endl;
    
}


int main()
{
    srand(static_cast<unsigned> (time(NULL)));        // 初始化随机数发生器
    int number = rand();
    int remainder = number % MAX_TYPE;
    
    string purposes[3] = { "DomesticShort","DomesticLong","International" };
    string types[2] = {"free","team"};
    TicketOffice tickOffice(0);//初始化售票处
    TravelAgency travelAgency(0);//初始化旅行社
    
    for (int i = 0; i < 5; i++) {//初始化旅行社
        int num = rand() % 3;
        Team temp(0,0, purposes[num]);
        travelAgency.teams[i] = temp;
        //cout << "旅行团" << i+1 << "的目的地是" << purposes[num] << endl;
    }
    
    
    
    Passenger passengers[62];//初始化旅客
    for (int i = 0; i < 62; i++) {
        int num1 = rand() % 3;
        int num2 = rand() % 2;
        int num3 = rand() % 4;
        char name = '1';
        if (i < 26)
            name = 'a' + i;
        else if (i >= 52)
            name = '0' + i-52;
        else
            name = 'A' + i-26;
        string purpose = purposes[num1];
        string type = types[num2];
        passengers[i].toTravel(name, type, purpose, num3, tickOffice, travelAgency);
    }
    
    travelAgency.totlaInfo();
    tickOffice.totalInfo();
    
    
    
    return 0;
}
