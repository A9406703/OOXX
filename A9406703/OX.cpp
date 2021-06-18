#include"OX.h"
#include"iostream"
using namespace std;
OX::OX() {

}
void OX::draw() {//畫棋盤
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << table[i][j] << " ";
        }
        cout << "|" << endl << "-------------" << endl;
    }
}

void OX::wrong() {//輸出錯誤訊息
    cout << "按錯，重按！" << endl;
    system("pause");
}

bool OX::setPosition(int position, int& round) {//畫圈畫叉
    //回合
    switch (position) {
    case 0://退出
        break;
    case 1:
        if (table[2][0] == '\0') {//判斷是否可放入O或X
            table[2][0] = (round % 2 == 1) ? 'O' : 'X';//放入O或X
            round++;//回合數+1
            break;//跳出switch
        }
        return false;//已有O或X,回傳不可放入
    case 2:
        if (table[2][1] == '\0') {
            table[2][1] = (round % 2 == 1) ? 'O' : 'X';
            round++;
            break;
        }
        return false;
    case 3:
        if (table[2][2] == '\0') {
            table[2][2] = (round % 2 == 1) ? 'O' : 'X';
            round++;
            break;
        }
        return false;
        break;
    case 4:
        if (table[1][0] == '\0') {
            table[1][0] = (round % 2 == 1) ? 'O' : 'X';
            round++;
            break;
        }
        return false;
        break;
    case 5:
        if (table[1][1] == '\0') {
            table[1][1] = (round % 2 == 1) ? 'O' : 'X';
            round++;
            break;
        }
        return false;
        break;
    case 6:
        if (table[1][2] == '\0') {
            table[1][2] = (round % 2 == 1) ? 'O' : 'X';
            round++;
            break;
        }
        return false;
    case 7:
        if (table[0][0] == '\0') {
            table[0][0] = (round % 2 == 1) ? 'O' : 'X';
            round++;
            break;
        }
        return false;
    case 8:
        if (table[0][1] == '\0') {
            table[0][1] = (round % 2 == 1) ? 'O' : 'X';
            round++;
            break;
        }
        return false;
    case 9:
        if (table[0][2] == '\0') {
            table[0][2] = (round % 2 == 1) ? 'O' : 'X';
            round++;
            break;
        }
        return false;
    }
    return true;//回傳true代表可放入且已放入
}

bool OX::gameover() {
    //判斷勝負
    for (int i = 0; i < 3; i++) {
        if (table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][0] != '\0') {//橫向
            return true;//有人贏了
        }
        else if (table[0][i] == table[1][i] && table[1][i] == table[2][i] && table[0][i] != '\0') {//直向
            return true;
        }
        else if (table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[0][2] != '\0') {//斜線
            return true;
        }
        else if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0] != '\0') {//反斜線
            return true;
        }
    }
    return false;//沒人贏
}

bool  OX::whoFirst() {
    int select=3;
    while (select != 0 && select != 1 && select != 2) {
        cout << "按1先手，按2後手(按0退出) : ";
        cin >> select;
        switch (select) {
        case 0:
            break;
        case 1:
            return false;//電腦後手
            break;
        case 2:
            return true;//電腦先手
            break;
        default:
            cout << "按錯，重來！";
        }
    }
}
