#include <iostream>  
#include <conio.h> 
#include <windows.h> 
using namespace std;

void goldOreInput(int goldOre) {
    cout << "Gold Ore: " << goldOre << "\n\n";
}

int leftRightEdge(int x) {
    if (x < 0) {
        x = 9;
    }
    else if (x > 9) {
        x = 0;
    }
    else {
        x = x;
    }
    return x;
}

int upDownEdge(int y) {
    if (y < 0) {
        y = 9;
    }
    else if (y > 9) {
        y = 0;
    }
    else {
        y = y;
    }
    return y;
}

int main() {
    system("mode con cols=40 lines=14");
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    const int H = 10, W = 10;
    char tabl[H][W];
    int x = 5, y = 5;
    char step;

    int stoneX, stoneY;

    int  goldOre = 0, magnetProfit;
    bool magnetOn = false;
    int stepWithMagnet = 5;
    int magnetX, magnetY;
    magnetX = rand() % 10;
    magnetY = rand() % 10;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            tabl[i][j] = '*';
        }
    }
    tabl[magnetX][magnetY] = 'V';

    while (true) {
        system("cls");
        goldOreInput(goldOre);

        stoneX = rand() % 10;
        stoneY = rand() % 10;
        tabl[stoneX][stoneY] = 'O';

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                magnetProfit = 8;

                if ((tabl[i][j] == 'O') && (i == x) && (j == y)) {
                    system("cls");
                    cout << "\n\n               You lost\n\n";
                    system("pause");
                    return 0;
                }

                if ((i + 1 == x) || (i - 1 == x)) {
                    magnetProfit--;
                }
                else if ((j + 1 == y) || (j - 1 == y)) {
                    magnetProfit--;
                }

                //перемещение между краями  
                x = leftRightEdge(x);
                y = upDownEdge(y);

                if ((i == x) && (j == y)) {
                    tabl[i][j] = '1';
                    cout << tabl[i][j] << ' ';
                    tabl[i][j] = '*';
                }
                else {
                    cout << tabl[i][j] << ' ';
                }
            }
            cout << endl;
        }
        if (magnetOn == true) {
            if (stepWithMagnet > 0) {
                stepWithMagnet--;
            }
            if (stepWithMagnet <= 0) {
                magnetOn = false;
            }
        }

        step = _getch();
        switch (step) {
        case 'd': 
            y++;
            break;
        case 'a': 
            y--;
            break;
        case 'w': 
            x--;
            break;
        case 's': 
            x++;
            break;
        }

        goldOre++;
        if (magnetOn == true) {
            goldOre += magnetProfit;
        }

        if ((magnetX == x) && (magnetY == y)) {
            magnetOn = true;
            magnetX = -1;
            magnetY = -1;
            goldOre--;
        }
    }
}
