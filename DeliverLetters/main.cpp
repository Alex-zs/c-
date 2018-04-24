#include <iostream>
#include <string>
using namespace std;

class Letter{
  public:
    string getSenderName(){
      return senderName;
    }
    string getRecipientName(){
      return recipientName;
    }
    string getContent(){
      return content;
    }
    Letter(string newAddress, string newContent, string newSenderName, string newRecipientName);
  private:
    string address;
    string content;
    string senderName;
    string recipientName;
};

Letter::Letter(string newAddress, string newContent, string newSenderName, string newRecipientName){
  address = newAddress;
  content = newContent;
  senderName = newSenderName;
  recipientName = newRecipientName;
}

class Recipient{
  public:
    void receiveLetter(Letter  letter);
    string getName(){
      return name;
    }
    Recipient(string newName);
  private:
    string name;
};

Recipient::Recipient(string newName){
  name = newName;
}

void Recipient::receiveLetter(Letter  letter){
  cout << "收到邮件，信件的内容是：" << letter.getContent() << endl;
}

class Postman {
  public:
    void deliverLetter(Letter  letter);
    Postman(string newName);
  private:
    string name;
};

Postman::Postman(string newName){
  name = newName;
}

void Postman::deliverLetter(Letter letter){
  cout << "我是邮递员" << name << ",马上投递信件，收件人是：" << letter.getRecipientName() << endl;
}



class PostOffice {
  
  public:
   PostOffice(Postman newTom, Postman newJerry); 
   double dealService(Letter  letter, string type);
   void charge(double postage);
   Postman  assignPostman(string type);
  private:
   Postman tom;
   Postman jerry;
};

PostOffice::PostOffice(Postman newTom, Postman newJerry): tom(newTom),jerry(newJerry) {
  
}

double PostOffice::dealService(Letter  letter, string type){
  cout << "收到信件，收信人是：" << letter.getRecipientName() << " 邮费是";
  if(type == "EMS"){
    cout << 15 << "元" << endl;
    return 15;
  }
  else{
    cout << 1 << "元" << endl;
    return 1;
  }
}

Postman PostOffice::assignPostman(string type){
  if(type == "EMS"){
    return jerry;
  }
  else{
    return tom;
  }
}


class Sender {
  
  public:
    Sender(string newName);
    string sendLetter(Letter  letter, PostOffice  oucBranch, string type);
    void pay(PostOffice oucBranch,double postage);
    string getName(){
      return name;
    }
  private:
    string name;
};
Sender::Sender(string newName) {
  name = newName;
};

string Sender::sendLetter(Letter  letter, PostOffice oucBranch, string type){
  cout << "我要寄信，收信人是：" << letter.getRecipientName() << " 选择投递方式是：" << type << endl;
  if(type == "surface mail") {
    return "surface mail";
  }
  else {
    return "EMS";
  }

}

void Sender::pay(PostOffice oucBranch,double postage){
  cout << "支付邮费" << postage << "元" << endl;
  cout << "收到邮费" << postage << "元" << endl;
}



int main() {
  Sender zhang("Zhang Haifan");
  Letter letter("信息学院南楼A310","Happy birthday, Huiming",zhang.getName(),"Wang Huiming");
  Postman tom("Tom");
  Postman jerry("Jerry");
  PostOffice oucBranch(tom,jerry);
  Recipient wang("Wang Huiming");
  string type = zhang.sendLetter(letter,oucBranch,"EMS");
  double postage = oucBranch.dealService(letter,type);
  zhang.pay(oucBranch,postage);
  Postman postman = oucBranch.assignPostman(type);
  postman.deliverLetter(letter);
  wang.receiveLetter(letter);

  return 0;
}
