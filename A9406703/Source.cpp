#include <iostream>
#include <iomanip>
#include"OX.h"
using namespace std;



int main() {
    srand(time(NULL));//�H���w�q�ŧi
    OX game;
    int select = 0;//���
    //char table[rowSize][columnSize] = { '\0' };//�ŧi�@�ӴѽL
    int position = 0, round = 1;//�e����m,�^�X
    bool finish = false, comFirst = true;//�C���O�_����,�H���j�Ԯɹq���O�_����

    cout << "�п�ܹC���Ҧ� :" << endl << " 1.�H���j�� 2.�H�H�j�� ( ��0�h�X ) :";
    cin >> select;
    switch (select) {
    case 0://�h�X
        break;
    case 1://�H���j��
        //�M�w�����
        comFirst = game.whoFirst();

        if (select == 0)//���a��ܰh�X
            break;
        //�C���}�l
        game.draw();//�e��l
        cout << "��l��ӼƦr��L(��0�h�X)" << endl;

        while (!finish) {//�C���O�_����
            if (comFirst) {//�P�_�^�X
                position = rand() % 9 + 1;//1`9�H���]�Ʀr
                if (game.input(position, round)) {//�p�G�i��,input�^��true,��q�����X��զ^��X��
                    comFirst = false;
                }
            }
            else {//���a���^�X
                cin >> position;
                if (game.input(position, round)) {//�p�G�i��,input�^��true,��q�����X��զ^���X��
                    comFirst = true;
                }
                else {
                    game.wrong();//���a�����~��X���~�T��,�q�������ٸ����~�T���ӥ��y
                }
            }
            if (position == 0) {//���a�M�w�h�X�C��
                finish = true;//�����C������
                break;
            }

            system("CLS");//�M�z�e��
            game.draw();
            cout << "��l��ӼƦr��L(��0�h�X)" << endl;

            finish = game.gameover();//�P�_�O�_���HĹ�F
            if (finish) {
                round % 2 == 1 ? cout << "X" : cout << "O";//�q�L�^�X�ƧP�_�o�^�X�O�֥X��
                cout << " Ĺ�F" << endl;
            }
            else if (round > 9) {//�^�X�W�L9�����S�HĹ
                break;//���X�j��
            }
        }
        if (!finish)
            cout << "����" << endl;
        break;
    case 2://�H�H
        game.draw();
        cout << "��l��ӼƦr��L(��0�h�X)" << endl;
        while (!finish) {
            cin >> position;
            if (position == 0) {
                finish = true;
                break;
            }
            if (!game.input(position, round))
                game.wrong();
            system("CLS");
            game.draw();
            cout << "��l��ӼƦr��L(��0�h�X)" << endl;
            finish = game.gameover();
            if (finish) {
                round % 2 == 1 ? cout << "X" : cout << "O";
                cout << " Ĺ�F" << endl;
            } else if (round > 9) {//�^�X�W�L9�����S�HĹ
                break;//���X�j��
            }
        }
        if (!finish)
            cout << "����" << endl;
        break;
    }


    system("pause");
    return 0;
}