#include <iostream>
#include <string>
using namespace std;

class Commodity {
    public:
        Commodity();
        Commodity(string,double,int);
        void printInfo();
        double sum_price();
    private:
        string name;
        double price;
        int num;
};

Commodity::Commodity() {
    name = "NULL";
    price = 0;
    num = 0;
}
Commodity::Commodity(string name_2, double price_2, int num_2) {
    name = name_2;
    price = price_2;
    num = num_2;
}

void Commodity::printInfo() {
    cout << name << "," << price << "," << num << endl;
}

double Commodity::sum_price() {
    return price * num;
}

class Cart {
    public:
        Cart();
        void addItem(Commodity);
        double checkout();
        void printInvoice();
    private:
        Commodity iterms[20];
        int itemNum;
};

Cart::Cart() {
    itemNum = 0;
}

void Cart::addItem(Commodity item) {
    iterms[itemNum] = item;
    itemNum++;
}

double Cart::checkout(){
    double sum = 0;
    for(int i = 0; i < itemNum; i++) {
        sum = iterms[i].sum_price() + sum;
    }
    cout << "您需要支付" << sum << "元" << endl;

    return sum;
}

void Cart::printInvoice() {
    for(int i = 0; i < itemNum; i++) {
        iterms[i].printInfo();
    }
}

int main() {
    Commodity tShirt("Tshirt", 79, 2);
    Commodity suit("suit", 1099 , 1);
    Commodity hat("hat", 129, 3);
    Commodity tv("tv set", 4899, 1);
    Commodity ac("air condition", 5280, 1);

    Cart myCart;
    myCart.addItem(tShirt);
    myCart.addItem(suit);
    myCart.addItem(hat);
    myCart.addItem(tv);
    myCart.addItem(ac);

    myCart.checkout();
    myCart.printInvoice();

    return 0;
}
