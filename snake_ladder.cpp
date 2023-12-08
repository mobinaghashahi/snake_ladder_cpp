#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int snakeHead[8]={14,27,35,50,70,77,86,99};
int snakeTail[8]={3,19,9,5,48,32,56,21};

// Check for snakes and ladders
int snakeHomeCheck(int position){
    for (int index=0;index<=8;index++){
        if(position==snakeHead[index])
            return snakeTail[index];
    }
    return position;
}

int rollDice() {
    return rand() % 6 + 1;
}

void createMap(int position1,int position2){
    cout<<endl;
    cout<<endl;
    for(int index=0;index<=100;index++){
            for(int indexSnake=0;indexSnake<8;indexSnake++){
                if(index==snakeHead[indexSnake])
                {
                    cout<<"S";
                    goto endS;
                }
            }
        if(position1==index)
            cout<<"A";
        else if(position2==index)
            cout<<"B";
        else if(index==snakeTail[index])
            cout<<"T";
        else
            cout<<"_";
            endS:;
    }
    cout<<"END";
    cout<<endl;
    cout<<endl;
}

int main() {
    srand(time(0)); // Seed for random number generation
    int player1 = 0, player2 = 0;
    int currentPlayer = 1; // Player 1 starts

    while (player1 < 100 && player2 < 100) {
             createMap(player1,player2);
        // Switch players
        if (currentPlayer == 1) {
            cout << "Player 1's turn. Press Enter to roll the dice...";
            cin.get();
            int dice = rollDice();
            cout << "You rolled a " << dice << endl;
            player1 += dice;
            cout << "Player 1 is now at position " << player1 << endl;
            currentPlayer = 2;
            player1=snakeHomeCheck(player1);
        } else {
            cout << "Player 2's turn. Press Enter to roll the dice...";
            cin.get();
            int dice = rollDice();
            cout << "You rolled a " << dice << endl;
            player2 += dice;
            cout << "Player 2 is now at position " << player2 << endl;
            currentPlayer = 1;
            player2=snakeHomeCheck(player2);
        }
    }

    // Determine the winner
    if (player1 >= 100) {
        cout << "Player 1 wins!" << endl;
    } else if (player2 >= 100){
        cout << "Player 2 wins!" << endl;
    }

    return 0;
}
