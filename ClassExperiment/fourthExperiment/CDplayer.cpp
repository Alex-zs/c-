#include <iostream>
#include <string>
using namespace std;

class CD {
    public:
        void listSongs(); // 列出CD的内容
        string getSinger();
    private:
        string singer = "周杰伦"; // 歌手的名字。
        string songs[6] = {"青花瓷","菊花台","双节棍","东风破","珊瑚海","稻香"}; // 每张专辑6首歌的名字。
};

string CD::getSinger() {
    return singer;
}
void CD::listSongs() {
    cout << "Singer:" << singer << endl;
    for(int i = 0; i < 6; i++) {
        cout << i << ". " << songs[i] << endl;
    }
}

class CDPlayer{
    public:
        CDPlayer();
        void showMenu();
        void insertCD(CD *c);
        CD * ejectCD();
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
        cout << "Please insert CD first" << endl;
    }
    else{
        cout << "正在播放" << cd->getSinger() << "CD......" << endl;
        cd->listSongs();
    }
}

void CDPlayer::insertCD(CD *c) {
    cd = c;
}

CD* CDPlayer::ejectCD() {
    cout << "弹出了" << cd->getSinger() << "的CD......" << endl;
    cd = NULL;
    return NULL;
}
int main() {
    CD cd;
    cd.listSongs();
    CDPlayer player;
    player.showMenu();
    player.play();
    player.insertCD(&cd);
    player.play();
    player.ejectCD();
    return 0;
}
