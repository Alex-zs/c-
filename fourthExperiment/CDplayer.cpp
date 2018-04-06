#include <iostream>
#include <string>
using namespace std;

class CD {
    public:
        void listSongs(); // 列出CD的内容
    private:
        string singer = "周杰伦"; // 歌手的名字。
        string songs[6] = {"青花瓷","菊花台","双节棍","东风破","珊瑚海","稻香"}; // 每张专辑6首歌的名字。
};

void CD::listSongs() {
    cout << "Singer'Name:" << singer << endl;
    for(int i = 0; i < 6; i++) {
        cout << i << ". " << songs[i] << endl;
    }
}

class CDPlayer{
    public:
        CDPlayer();
        void showMenu();
        void insertCD(CD *c);
        CD *ejectCD();
        void play();
    private:
        CD *cd;
        bool cdIn;
};

CDPlayer::CDPlayer() {
}

void CDPlayer::showMenu() {
    cout << "*********************************" << endl;
    cout << "* 1. 播放 CD                    *" << endl;
    cout << "* 2. 插入 CD                    *" << endl;
    cout << "* 3. 弹出 CD                    *" << endl;
    cout << "* 0. 关机                       *" << endl;
    cout << "*********************************" << endl;
}

void CDPlayer::play() {
    if(cd == NULL) {
        cout << "Please insert CD first";
    }
    else{
        cout << "正在播放" << cd->singer << "CD......" << endl;
        cd->listSongs();
    }
}

void CDPlayer::insertCD(CD *c) {
    cd = c;
}
        

int main() {
    CD cd;
    cd.listSongs();
    return 0;
}
