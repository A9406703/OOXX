#include"OX.h"
#include"iostream"
using namespace std;
OX::OX() {

}
void OX::draw() {//�e�ѽL
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << table[i][j] << " ";
        }
        cout << "|" << endl << "-------------" << endl;
    }
}

void OX::wrong() {//��X���~�T��
    cout << "�����A�����I" << endl;
    system("pause");
}

bool OX::setPosition(int position, int& round) {//�e��e�e
    //�^�X
    switch (position) {
    case 0://�h�X
        break;
    case 1:
        if (table[2][0] == '\0') {//�P�_�O�_�i��JO��X
            table[2][0] = (round % 2 == 1) ? 'O' : 'X';//��JO��X
            round++;//�^�X��+1
            break;//���Xswitch
        }
        return false;//�w��O��X,�^�Ǥ��i��J
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
    return true;//�^��true�N��i��J�B�w��J
}

bool OX::gameover() {
    //�P�_�ӭt
    for (int i = 0; i < 3; i++) {
        if (table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][0] != '\0') {//��V
            return true;//���HĹ�F
        }
        else if (table[0][i] == table[1][i] && table[1][i] == table[2][i] && table[0][i] != '\0') {//���V
            return true;
        }
        else if (table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[0][2] != '\0') {//�׽u
            return true;
        }
        else if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0] != '\0') {//�ϱ׽u
            return true;
        }
    }
    return false;//�S�HĹ
}

bool  OX::whoFirst() {
    int select=3;
    while (select != 0 && select != 1 && select != 2) {
        cout << "��1����A��2���(��0�h�X) : ";
        cin >> select;
        switch (select) {
        case 0:
            break;
        case 1:
            return false;//�q�����
            break;
        case 2:
            return true;//�q������
            break;
        default:
            cout << "�����A���ӡI";
        }
    }
}
