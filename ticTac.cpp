/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eddie
 *
 * Created on March 25, 2017, 12:24 PM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

const int ROW_LENGTH = 3;
const int COL_LENGTH = 3;
const int BOARD_SIZE = ROW_LENGTH * COL_LENGTH;

int p1Pick = 0;
int p2Pick = 0;
int currentPlayer = 0; // 0 = player 1, 1 = player 2
int myTracker[BOARD_SIZE];

void printEachNum(int row,int col,bool pipe) {
    if (myTracker[row * ROW_LENGTH + (col)] == 0) 
    {
        printf("  %d  %s", row * ROW_LENGTH + col + 1, (pipe == true)?"|":"");
    } else {
        printf("  %s  |", (myTracker[row * ROW_LENGTH + (col)] == 1) ? "X" : "O");
    }
}

void printTicTacBoard()
{
    printf("        Tic Tac Toe          \n");
    printf("Player 1 <X>  -  Player 2 <O>\n");
    
    int eachNum = 1;
    
    for (int row = 0; row < ROW_LENGTH; row++)
    {
        for (int col = 0; col < COL_LENGTH; col++)
        {
            if (col != (COL_LENGTH-1))
            {
                 printEachNum(row,col,true);
                
            }
            else
            {
                 printEachNum(row,col,false);
            }
            eachNum++;
        }
        
        
            if (row != (ROW_LENGTH-1))
            {
            printf ("\n________________\n", eachNum);
            }
            else
            {
            printf ("\n");
            }
    }
    

}

bool hasWon()
{
    // left to right
    bool caseOne = (myTracker[0] != 0) && ((myTracker[0] == myTracker[1]) && (myTracker[1] == myTracker[2]));
    bool caseTwo = (myTracker[3] != 0) && ((myTracker[3] == myTracker[4]) && (myTracker[4] == myTracker[5]));
    bool caseThree = (myTracker[3] != 0) && ((myTracker[3] == myTracker[4]) && (myTracker[4] == myTracker[5]));
     
    if( caseOne ||
        caseTwo ||
        caseThree )
    {
        printf ("YES\n");
        return true;
    }
    
    caseOne = (myTracker[0] != 0) && ((myTracker[0] == myTracker[3]) && (myTracker[3] == myTracker[6]));
    caseTwo = (myTracker[1] != 0) && ((myTracker[1] == myTracker[4]) && (myTracker[4] == myTracker[7]));
    caseThree = (myTracker[2] != 0) && ((myTracker[2] == myTracker[5]) && (myTracker[5] == myTracker[8]));
    
    //up to down
    if( caseOne ||
        caseTwo ||
        caseThree )
    {
        return true;
    }
    
    caseOne = (myTracker[0] != 0) && ((myTracker[0] == myTracker[4]) && (myTracker[4] == myTracker[8]));
    caseTwo = (myTracker[6] != 0) && ((myTracker[6] == myTracker[4]) && (myTracker[4] == myTracker[2]));
    
        //up to down
    if(caseOne || caseTwo)
    {
        return true;
    }
    
    
    return false;
}

bool parseUserInput()
{
    printf ("Player %d, enter a number: ", (currentPlayer==0)?1:2);

    int inputNumber = 0;
   
    cin >> inputNumber;

    while( (inputNumber <= 0) || (inputNumber>BOARD_SIZE) || (myTracker[inputNumber-1] != 0) )
    {
        printf ("Incorrect number, please try1 again: ");
        cin >> inputNumber;
    }
    
    myTracker[inputNumber-1] = (currentPlayer==0)?1:2; // 1 = player 1, 2 = player 2
    
    if(hasWon())
    {
        printf ("Player %s has won!", (currentPlayer==0)?"1":"2");
        return true;
    }
    currentPlayer ^= 1;
    
    return false;
}

void playTicTac()
{
    int times = 0;
    while(times < 9)
    {
        printTicTacBoard();
        if(parseUserInput())
        {
            break;
        }
        times++;
    }
    
    if(times==9)
    {
        printf ("TIED\n");
    }
}

/*
 * 
 */
int main(int argc, char** argv) {

    playTicTac();
    
    return 0;
}

