#include <iostream>
#include <iomanip>
#include"OX.h"
using namespace std;



int main() {
    srand(time(NULL));//隨機定義宣告
    OX game;
    int select = 0;//選擇
    //char table[rowSize][columnSize] = { '\0' };//宣告一個棋盤
    int position = 0, round = 1;//畫的位置,回合
    bool finish = false, comFirst = true;//遊戲是否結束,人機大戰時電腦是否先手

    cout << "請選擇遊戲模式 :" << endl << " 1.人機大戰 2.人人大戰 ( 按0退出 ) :";
    cin >> select;
    switch (select) {
    case 0://退出
        break;
    case 1://人機大戰
        //決定先後手
        comFirst = game.whoFirst();

        if (select == 0)//玩家選擇退出
            break;
        //遊戲開始
        game.draw();//畫格子
        cout << "格子對照數字鍵盤(按0退出)" << endl;

        while (!finish) {//遊戲是否結束
            if (comFirst) {//判斷回合
                position = rand() % 9 + 1;//1`9隨機跑數字
                if (game.input(position, round)) {//如果可放,input回傳true,把電腦的出手調回後出手
                    comFirst = false;
                }
            }
            else {//玩家的回合
                cin >> position;
                if (game.input(position, round)) {//如果可放,input回傳true,把電腦的出手調回先出手
                    comFirst = true;
                }
                else {
                    game.wrong();//玩家按錯才輸出錯誤訊息,電腦按錯還跳錯誤訊息太丟臉
                }
            }
            if (position == 0) {//玩家決定退出遊戲
                finish = true;//直接遊戲結束
                break;
            }

            system("CLS");//清理畫面
            game.draw();
            cout << "格子對照數字鍵盤(按0退出)" << endl;

            finish = game.gameover();//判斷是否有人贏了
            if (finish) {
                round % 2 == 1 ? cout << "X" : cout << "O";//通過回合數判斷這回合是誰出手
                cout << " 贏了" << endl;
            }
            else if (round > 9) {//回合超過9次仍沒人贏
                break;//跳出迴圈
            }
        }
        if (!finish)
            cout << "平手" << endl;
        break;
    case 2://人人
        game.draw();
        cout << "格子對照數字鍵盤(按0退出)" << endl;
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
            cout << "格子對照數字鍵盤(按0退出)" << endl;
            finish = game.gameover();
            if (finish) {
                round % 2 == 1 ? cout << "X" : cout << "O";
                cout << " 贏了" << endl;
            } else if (round > 9) {//回合超過9次仍沒人贏
                break;//跳出迴圈
            }
        }
        if (!finish)
            cout << "平手" << endl;
        break;
    }


    system("pause");
    return 0;
}